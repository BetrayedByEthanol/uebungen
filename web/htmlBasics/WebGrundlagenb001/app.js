// const cors = require('cors');
const express = require("express");
const fs = require('fs');
const http = require('http');
const https = require('https');
var path = require("path");
var morgan = require('morgan');
var passport = require('passport');
var mongoose = require('mongoose');
const User = require('./Users');
const LocalStrategy = require('passport-local').Strategy;

var os = require('os');
var ifaces = os.networkInterfaces();

const app = express();
// app.use(cors());
// app.options('*', cors());
const port = 5050;


const url = 'mongodb://10.42.53.5:27017';
const MongoClient = require('mongodb').MongoClient;
ObjectID = require('mongodb').ObjectID
const client = new MongoClient(url, {
    useUnifiedTopology: true
});
var db;

mongoose.connect(url + '/FIAN19-II', { useNewUrlParser: true, useUnifiedTopology: true, useFindAndModify: false });

passport.use(new LocalStrategy(function (username, password, done) {
    User.getUserByUsername(username, function (err, user) {
        if (err) throw err;
        if (!user) {
            return done(null, false, { message: 'Unknown User' });
        }

        User.comparePassword(password, user.password, function (err, isMatch) {
            if (err) throw err;
            if (isMatch) {
                user.token = User.generateJWT();
                var today = new Date();
                today.setDate(today.getDate() + 7);
                user.tokenExpirationDate = today;
                User.findOneAndUpdate({ username: user.username }, { token: user.token, tokenExpirationDate: user.tokenExpirationDate }, function (err, doc) {
                    if (err) throw err;
                });
                user.password = "";
                return done(null, user);
            } else {
                return done(null, false, { message: 'Invalid password' });
            }
        });
    });
}
));

passport.serializeUser(function (user, done) {
    done(null, user.id);
});

passport.deserializeUser(function (id, done) {
    User.getUserById(id, function (err, user) {
        done(err, user);
    });
});

app.use(passport.initialize());

app.use(morgan('common'));

app.use(express.json());

// Redirect Unauthorized
app.use((req, res, next) => {
    if (req.url.includes('login') || req.url.includes('register')) {
        next();
    } else {
        var cookies = req.headers.cookie;
        if (cookies != undefined) {
            cookies = cookies.split(';');
            var usertoken = cookies.find(cookie => { return cookie.includes('logTok') });
            if (usertoken != undefined) {
                usertoken = usertoken.substring(usertoken.indexOf('=') + 1);
                db.collection('users').findOne({
                    'token': usertoken
                }).then(result => {
                    if (result != null) {
                        next();
                    } else {
                        res.redirect('/login.html');
                    }
                });
            } else {
                res.redirect('/login.html');
            }
        } else {
            res.redirect('/login.html');
        }
    }
});

// Login User
app.post('/login',
    passport.authenticate('local'),
    function (req, res) {
        res.send(req.user);
    }
);

// Register User
app.post('/register', function (req, res) {
    var password = req.body.password;
    var password2 = req.body.password2;
    var query = User.findOne({ username: req.body.username });
    query.exec((err, result) => {
        if (err) return console.log(err);
        if (password == password2) {
            if (result == null) {
                var newUser = new User({
                    username: req.body.username,
                    email: req.body.email,
                    password: req.body.password
                });

                User.createUser(newUser, function (err, user) {
                    if (err) throw err;
                    res.send(user).end()
                });
            } else {
                res.status(500).send("{erros: \"User already exists\"}").end()
            }
        } else {
            res.status(500).send("{erros: \"Passwords don't match\"}").end()
        }
    })
});


app.get('/strategySample', (req, res) => {
    const StartYourConstWithCaps = (req.connection.remoteAddress.includes("::1")) ? getIP() : req.connection.remoteAddress;
    db.collection('obliquestrategies').aggregate([{
        $facet: {
            rarelyDisplayed: [{ $sort: { timesDisplayed: 1 } }, { $limit: 10 }, { $addFields: { rating: { $sum: "$votes.status" } } }],
            displayMoreOften: [{ $sort: { lastViewed: 1 } }, { $limit: 10 }, { $addFields: { rating: { $sum: "$votes.status" } } }],
            topRated: [{ $addFields: { rating: { $sum: "$votes.status" } } }, { $sort: { rating: -1 } }, { $limit: 10 }]
        }
    }, {
        $project: {
            data: {
                $concatArrays: ["$rarelyDisplayed", "$displayMoreOften", "$topRated"]
            }
        }
    }, {
        $unwind: "$data"
    }, {
        $replaceWith: "$data"
    }, {
        $project: {
            votes: {
                $filter: {
                    input: "$votes",
                    as: "vote",
                    cond: { $eq: ["$$vote.ip", StartYourConstWithCaps] }
                }
            },
            phrase: 1,
            _id: 1,
            category: 1,
            rating: 1,
            lastViewed: 1,
            timesDisplayed: 1,
        }
    }
    ]).toArray(function (err, result) {
        if (err) throw err;
        var id = Math.floor(Math.random() * result.length);
        result[id].display = true;
        res.json(result);
        db.collection('obliquestrategies').updateOne({ _id: ObjectID(result[id]._id) }, {
            $set: {
                lastViewed: new Date(),
                timesDisplayed: result[id].timesDisplayed + 1
            }
        }, function (erro, resu) {
            if (erro) throw erro;
            console.log(resu);
        });
    });
});

app.get('/strategies/:strategyID', function (req, res) {
    console.log(req.params);

    db.collection('obliquestrategies').findOne({
        '_id': ObjectID(req.params.strategyID)
    }, function (err, result) {
        if (err) throw err;
        console.log(result);
        res.json(result);
    });
});


app.get('/strategies', (req, res) => {

    db.collection('obliquestrategies').find().toArray(function (err, result) {
        if (err) throw err;
        res.json(result);
    });

});

app.get('/strategies/:strategyID/votes', function (req, res) {
    console.log(req.params);

    db.collection('obliquestrategies').findOne({
        '_id': ObjectID(req.params.strategyID)
    }).then(result => {
        console.log(result.votes);
        res.json(result.votes);
    });
});


app.vote = function (req, res, status) {

    var ip = req.connection.remoteAddress;
    if (ip.includes('::1')) ip = getIP();
    //TODO: Is there a better solution?
    db.collection('obliquestrategies').updateOne({
        _id: ObjectID(req.params.strategyID),
        "votes.ip": ip
    }, {
        $set: {
            "votes.$.status": status
        }
    }).then(result => {
        console.log(result);

        //create new vote object when no vote exists
        if (result.matchedCount == 0) {
            db.collection('obliquestrategies').updateOne({
                _id: ObjectID(req.params.strategyID)
            }, {
                $push: {
                    votes: {
                        ip: ip,
                        status: status
                    }
                }
            })
        }
        res.sendStatus(200);
    }).catch((err) => {
        console.log(err);
        res.sendStatus(404);
    });

};

app.post('/strategies/:strategyID/upvote', function (req, res) {
    app.vote(req, res, 1);
});

app.post('/strategies/:strategyID/downvote', function (req, res) {
    app.vote(req, res, -1);
});

app.post('/strategies/:strategyID/unvote', function (req, res) {
    app.vote(req, res, 0);
});

app.get('/challenge', (req, res) => {

    if (req.headers.message == 'OK Boomer') {
        res.sendFile(path.join(__dirname + "/src/img/boomer.webp"));
    } else {
        res.json({
            message: 'OK Boomer'
        });
    }

});

app.use(express.static("src"));

app.use(function (req, res, next) {
    res.statusCode = 404;
    res.sendFile(path.join(__dirname + "/src/error404.html"));
});


client.connect().then((client) => {
    db = client.db('FIAN19-II');
    //Server Key and Certificate as well as passphrase
    //Renew Self Signed key and certificate after 90 days with `openssl req -x509 -newkey rsa:4096 -keyout key.pem -out cert.pem -days 90` in Terminal and delete old one
    //Create the server using an SSL connection - Need to use HTTPS:// now
    https.createServer({
        key: fs.readFileSync('./key.pem'),
        cert: fs.readFileSync('./cert.pem'),
        passphrase: 'FIAN19'
    }, app).listen(5050, () => {
        console.log('Listening on 5050 for HTTPS')
    });
    //Server for Non-SSL connection
    app.listen(5080, () => {
        console.log('Listening on 5080 for HTTP')
    });
});

function getIP() {
    var ipAddresses = [];
    Object.keys(ifaces).forEach(function (ifname) {
        var alias = 0;

        ifaces[ifname].forEach(function (iface) {
            if ('IPv4' !== iface.family || iface.internal !== false) {
                // skip over internal (i.e. 127.0.0.1) and non-ipv4 addresses
                return;
            }

            if (alias >= 1) {
                // this single interface has multiple ipv4 addresses
                console.log(ifname + ':' + alias, iface.address);
            } else {
                // this interface has only one ipv4 adress
                ipAddresses.push(iface.address);
            }
            ++alias;
        });
    });
    return ipAddresses[0];
}

