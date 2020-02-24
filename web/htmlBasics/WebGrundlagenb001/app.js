// const cors = require('cors');
const express = require("express");
const fs = require('fs');
const https = require('https');
var path = require("path");
var morgan = require('morgan');
var os = require('os');
var ifaces = os.networkInterfaces();

const app = express();
// app.use(cors());
// app.options('*', cors());
const port = 5050;

const url = 'mongodb://10.42.53.5:27017';
const MongoClient = require('mongodb').MongoClient;
ObjectID = require('mongodb').ObjectID
const client = new MongoClient(url, { useUnifiedTopology: true });
var db;



app.use(morgan('common'));

app.use(express.json());

app.get('/strategySample', (req, res) => {
    db.collection('obliquestrategies').aggregate([{ 
        $sample: { size: 20 } } ,{ 
        $addFields: {
            rating: {$sum: "$votes.status"}}} , { 
        $project: { 
            votes: { 
                $filter: { 
                    input: "$votes", 
                    as: "vote", 
                    cond: { $eq: ["$$vote.ip", req.connection.remoteAddress] } } }, 
            phrase: 1, 
            _id: 1, 
            category: 1, 
            rating: 1 
        }
    }]).toArray(function (err, result) {
        if (err) throw err;
        res.json(result);
    });
});

app.get('/strategies/:strategyID', function (req, res) {
    console.log(req.params);

    db.collection('obliquestrategies').findOne({ '_id': ObjectID(req.params.strategyID) }, function (err, result) {
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

    db.collection('obliquestrategies').findOne(
        { '_id': ObjectID(req.params.strategyID) }
    ).then(result => {
        console.log(result.votes);
        res.json(result.votes);
    });
});


app.vote = function (req, res, status) {

    var ip = req.connection.remoteAddress;
    if(ip.includes('::1')) ip = getIP();
    //TODO: Is there a better solution?
    db.collection('obliquestrategies').updateOne(
        { _id: ObjectID(req.params.strategyID), "votes.ip": ip },
        { $set: { "votes.$.status": status } }
    ).then(result => {
        console.log(result);

        //create new vote object when no vote exists
        if (result.matchedCount == 0) {
            db.collection('obliquestrategies').updateOne(
                { _id: ObjectID(req.params.strategyID) },
                { $push: { votes: { ip: ip, status: status } } }
            )
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
        res.json({ message: 'OK Boomer' });
    }

});

app.use(express.static("src"));

app.use(function (req, res, next) {
    res.statusCode = 404;
    res.sendFile(path.join(__dirname + "/src/error404.html"));
});

client.connect().then((client) => {
    db = client.db('FIAN19-II');
    
    //Create the server using an SSL connection - Need to use HTTPS:// noww
    https.createServer({
        //Server Key and Certificate as well as passphrase
        key: fs.readFileSync('./key.pem'),
        cert: fs.readFileSync('./cert.pem'),
        passphrase: 'FIAN19'
    }, app).listen(5050, () => {
        console.log('Listening...')
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