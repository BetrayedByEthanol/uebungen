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
    const http = new XMLHttpRequest();
    http.open("GET", "/strategy");
    http.send();

    var setWait = window.setInterval(wait, 40);
}

function filterPhrases(category) {
    phrases = allPhrases.filter(p => { return p.category == category });
}


function getRating() {
    if (allPhrases[currentPhraseID].votes.length == 0) {
        document.getElementById('upvote').style.visibility = 'visible';
        document.getElementById('downvote').style.visibility = 'visible';
    } else if (allPhrases[currentPhraseID].votes[0].status == 1) {
        document.getElementById('upvote').style.visibility = 'visible';
        document.getElementById('downvote').style.visibility = 'hidden';
    } else {
        document.getElementById('upvote').style.visibility = 'hidden';
        document.getElementById('downvote').style.visibility = 'visible';
    }
    document.getElementById('rating').innerText = allPhrases[currentPhraseID].rating;
}

function vote(param) {
    if (allPhrases[currentPhraseID].votes.length != 0) {
        param = '/unvote';
        (allPhrases[currentPhraseID].votes[0].status == 1)? allPhrases[currentPhraseID].rating-- : allPhrases[currentPhraseID].rating++;
        allPhrases[currentPhraseID].votes = [];
    } else if(param.includes('upvote')){
        allPhrases[currentPhraseID].rating++;
        var status = 1
        allPhrases[currentPhraseID].votes.push(status);
    } else {
        allPhrases[currentPhraseID].rating--;
        var status = -1
        allPhrases[currentPhraseID].votes.push(status);
    }

    fetch('/strategies/' + allPhrases[currentPhraseID]._id + param, {
        method: "POST"
    }).then(res => {
        console.log(res.text());
    });
    getRating();
}

const http = new XMLHttpRequest();
http.open("GET", "/strategy");
http.onload = wennGeladen;
http.send();

