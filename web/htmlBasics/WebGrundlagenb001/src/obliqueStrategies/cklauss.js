var phrases;
var allPhrases;
var categories = [];
var toggleMe = false;
var autoRefresh;
var currentPhraseID;
var currentPhraseMongoID;
const server = 'http://localhost:5050';

var wennGeladen = function () {
    allPhrases = JSON.parse(http.responseText);
    for (var i = 0; i < allPhrases.length; i++) {
        allPhrases[i].id = i;
        allPhrases[i].category.forEach(x => {
            if (!categories.includes(x)) categories.push(x);
        });
    }
    phrases = allPhrases;
    refresh();

}

function toggler() {
    toggleMe = !toggleMe;
    if (toggleMe == true) {
        autoRefresh = window.setInterval(refresh, 10000);
        document.getElementById('autoRefresh').src = 'img/timeronb.png';
    } else {
        document.getElementById('autoRefresh').src = 'img/timeroffb.png';
        window.clearInterval(autoRefresh);
    }
}

function refresh() {
    var counter = 0;
    var wait = function () {
        const randomNumber = Math.floor(Math.random() * phrases.length);
        document.getElementById('content').innerText = phrases[randomNumber].phrase;
        counter++;
        if (counter > 20) {
            window.clearInterval(setWait);
            currentPhraseID = phrases[randomNumber].id;
            currentPhraseMongoID = phrases[randomNumber]._id;
            document.getElementById('category').innerText = phrases[randomNumber].category;
            getRating();
        }
    }
    var setWait = window.setInterval(wait, 40);
}

function filterPhrases(category) {
    phrases = allPhrases.filter(p => { return p.category == category });
}


function getRating() {
    if (allPhrases[currentPhraseID].votes.length == 0) {
        document.getElementById('upvote').style.visibility = 'visible';
        document.getElementById('downvote').style.visibility = 'visible';
    } else if (allPhrases[currentPhraseID].votes[0].voteStatus == 1) {
        document.getElementById('upvote').style.visibility = 'visible';
        document.getElementById('downvote').style.visibility = 'hidden';
    } else {
        document.getElementById('upvote').style.visibility = 'hidden';
        document.getElementById('downvote').style.visibility = 'visible';
    }
    document.getElementById('rating').innerText = allPhrases[currentPhraseID].upvotes - allPhrases[currentPhraseID].downvotes;
}

function vote(param) {
    if (allPhrases[currentPhraseID].votes.length != 0) {
        if (allPhrases[currentPhraseID].votes[0].voteStatus == 1) {
            allPhrases[currentPhraseID].upvotes--;
        } else {
            allPhrases[currentPhraseID].downvotes--;
        }
        param = 0;
        allPhrases[currentPhraseID].votes = [];
    } else {
        let data = {
            voteStatus: param
        };
        allPhrases[currentPhraseID].votes.push(data);
        (param == 1) ? allPhrases[currentPhraseID].upvotes++ : allPhrases[currentPhraseID].downvotes++;
    }
    console.log(param);
    let data = {
        ipAddress: 'mustBeReplayedThroughServer',
        voteStatus: param,
        phraseID: currentPhraseMongoID
    };

    fetch('/strategies/' + allPhrases[currentPhraseID]._id + '/upvote', {
        method: "POST",
        // headers: {
        //     'Content-Type': 'application/json'
        // },
        // body: JSON.stringify(data)
    }).then(res => {
        console.log(res.text());
    });
    getRating();
}

const http = new XMLHttpRequest();
http.open("GET", "/strategies");
http.onload = wennGeladen;
http.send();

