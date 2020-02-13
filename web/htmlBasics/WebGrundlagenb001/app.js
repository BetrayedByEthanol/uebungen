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

app.use(express.json());

app.post('/post', (req, res) => {

    req.body.ipAddress = req.connection.remoteAddress;
    console.log(req.body.phraseID);
    res.json({ message: 'hallo' });
    db.collection('obliquestrategies').findOne({ _id: ObjectID(req.body.phraseID) }, function (err, result) {
        if (err) throw err;
        if (result.votes.filter(e => { return ipAddress == req.body.ipAddress }).length == 0) {
            console.log('new vote');
            result.votes.push({ ipAddress: req.body.ipAddress, voteStatus: req.body.voteStatus });
        } else {
            console.log('update old vote');
            result.votes.filter(e => { return ipAddress == req.body.ipAddress }).voteStatus = req.body.voteStatus;
        }
        var upvotes = 0;
        var downvotes = 0;
        result.votes.forEach(v => {
            if (v.voteStatus == 1) upvotes++;
            if (v.voteStatus == -1) downvotes++;
        });
        result.upvotes = upvotes;
        result.downvotes = downvotes;
        console.log(result);
        var query = {  _id: result._id };
        var  values =  { $set: { upvotes: upvotes, downvotes: downvotes, votes: result.votes } }
        db.collection('obliquestrategies').updateOne(query, values , function (erro, resu) {
            if (erro) throw erro;
            console.log(resu);
        });
    });

});

app.get('/strategies', (req, res) => {

    db.collection('obliquestrategies').find().toArray(function (err, result) {
        if (err) throw err
        res.json(result);
    });

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


