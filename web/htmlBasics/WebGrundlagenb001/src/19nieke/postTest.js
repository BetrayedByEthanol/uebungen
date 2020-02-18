app.post('/post', (req, res) => {

    (req.connection.remoteAddress.includes('::1')) ? req.body.ipAddress = getIP() : req.body.ipAddress = req.connection.remoteAddress;
    console.log(req.body.phraseID);
    res.json({ message: 'hallo' });
    db.collection('obliquestrategies').findOne({ _id: ObjectID(req.body.phraseID) }, function (err, result) {
        if (err) throw err;
        if (result.votes.filter(e => { return e.ipAddress == req.body.ipAddress }).length == 0) {
            if (req.body.ipAddress.includes('::1')) req.body.ipAddress = getIP();
            result.votes.push({ ipAddress: req.body.ipAddress, voteStatus: req.body.voteStatus });
        } else {
            result.votes.filter(e => { return e.ipAddress == req.body.ipAddress })[0].voteStatus = req.body.voteStatus;
        }
        console.log(req.body.voteStatus);
        db.collection('obliquestrategies').updateOne({ _id: result._id }, { $set: { votes: result.votes } }, function (erro, resu) {
            if (erro) throw erro;
            console.log(resu);
        });
    });

});
