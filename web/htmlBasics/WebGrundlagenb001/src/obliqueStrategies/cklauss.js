var phrases;
var allPhrases;
var timer = 0;
var categories = [];
var toggleMe = false;
var autoRefresh;
var currentPhraseID;
var currentPhraseMongoID;

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
            timer = 0;
        }
    }
    var setWait = window.setInterval(wait, 40);
}

function filterPhrases(category) {
    phrases = allPhrases.filter(p => { return p.category == category });
}

function vote(vote) {
    if (vote == 1 && allPhrases[currentPhraseID].voted == 0) {
        allPhrases[currentPhraseID].upvotes++;
        allPhrases[currentPhraseID].voted = 1;
        document.getElementById('downvote').style.visibility = 'hidden';
    } else if (vote == 0 && allPhrases[currentPhraseID].voted == 0) {
        allPhrases[currentPhraseID].downvotes++;
        allPhrases[currentPhraseID].voted = -1;
        document.getElementById('upvote').style.visibility = 'hidden';
    } else if (allPhrases[currentPhraseID].voted == 1) {
        allPhrases[currentPhraseID].upvotes--;
        allPhrases[currentPhraseID].voted = 0;

    } else {
        allPhrases[currentPhraseID].downvotes--;
        allPhrases[currentPhraseID].voted = 0;

    }
    getRating();
}

function getRating() {
    if (allPhrases[currentPhraseID].voted == 0) {
        document.getElementById('upvote').style.visibility = 'visible';
        document.getElementById('downvote').style.visibility = 'visible';
    } else if (allPhrases[currentPhraseID].voted == 1) {
        document.getElementById('upvote').style.visibility = 'visible';
        document.getElementById('downvote').style.visibility = 'hidden';
    } else {
        document.getElementById('upvote').style.visibility = 'hidden';
        document.getElementById('downvote').style.visibility = 'visible';
    }
    document.getElementById('rating').innerText = allPhrases[currentPhraseID].upvotes - allPhrases[currentPhraseID].downvotes;
}

function vote(param) {
    const http = new XMLHttpRequest();
    const url = 'localhost:5050';
    let data = {
        ipAddress: 'mustBeReplayedThroughServer',
        voteStatus: param,
        phraseID: currentPhraseMongoID
    };

    fetch('http://localhost:5050/post', {
        method: "POST",
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(data)
    }).then(res => {
        console.log(res.text());
    })
}

function myIP() {
    if (window.XMLHttpRequest) xmlhttp = new XMLHttpRequest();
    else xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");

    xmlhttp.open("GET", "http://api.hostip.info/get_html.php", false);
    xmlhttp.send();

    hostipInfo = xmlhttp.responseText.split("\n");

    for (i = 0; hostipInfo.length >= i; i++) {
        ipAddress = hostipInfo[i].split(":");
        if (ipAddress[0] == "IP") return ipAddress[1];
    }

    return false;
}


const http = new XMLHttpRequest();
http.open("GET", "/strategies");
http.onload = wennGeladen;
http.send();