const url = 'mongodb://10.42.53.5:27017';
const MongoClient = require('mongodb').MongoClient;

MongoClient.connect(url, function (err, db) {
    if (err) throw err;
    var dbo = db.db('FIAN19-II');
    dbo.collection('obliquestrategies').find({}).toArray(function (err, result) {
        if (err) throw err;
        console.log(result);
        result.forEach(p => {
            var myQuery = { _id: p._id };
            var newValues = { $rename: { upvotes: 0, downvotes: 0, ipAddress: [] } }
            dbo.collection('obliquestrategies').updateOne(myQuery, {$set: { lastViewed: new Date() }}, function (err, res) {
                if (err) throw err;
                console.log(res);
            });
        });
     db.close();   
    });
});

