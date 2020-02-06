const express = require("express");
var path = require("path");
var morgan = require('morgan');


const app = express();
const port = 5050;

const url = 'mongodb://10.42.53.5:27017';
const MongoClient = require('mongodb').MongoClient;
ObjectID = require('mongodb').ObjectID
const client = new MongoClient(url, { useUnifiedTopology: true });
var db;

app.use(morgan('common'));

app.get('/strategies', (req, res) => {

    db.collection('obliquestrategies').find().toArray(function (err, result) {
        if (err) throw err
        res.json(result);
        console.log(result);
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

app.get('/strategies/:strategyID/votes', function (req, res) {
    console.log(req.params);

    db.collection('obliquestrategies').findOne(
        { '_id': ObjectID(req.params.strategyID) }
    ).then(result => {
        console.log(result.votes);
        res.json(result.votes);
    });
});

// vote function for up/down/unvote
app.vote = function(req, res, status) {

    var ip = req.headers['x-forwarded-for'] || req.connection.remoteAddress;
 
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
    app.listen(port, () => console.log(`Server listening on port ${port}!`));
});