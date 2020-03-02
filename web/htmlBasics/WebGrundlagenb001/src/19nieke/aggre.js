const url = 'mongodb://10.42.53.5:27017';
const MongoClient = require('mongodb').MongoClient;
const client = new MongoClient(url, { useUnifiedTopology: true });


client.connect().then((client) => {
    var db = client.db('FIAN19-II');
    db.collection('obliquestrategies').aggregate([{
        $sort: { positionInQueue: 1 }
    }, {
        $limit: 20
    }, {
        $addFields: {
            rating: { $sum: "$votes.status" }
        }
    }, {
        $project: {
            votes: {
                $filter: {
                    input: "$votes",
                    as: "vote",
                    cond: { $eq: ["$$vote.ip", '::1'] }
                }
            },
            phrase: 1,
            _id: 1,
            category: 1,
            rating: 1,
            lastViewed: 1,
            timesDisplayed: 1,
        }
    }]).toArray(function (err, result) {
        if (err) throw err;
        console.log(result);
        client.close();
    });
});