var phrases;
var allPhrases;
var timer = 0;
var categories = [];
var toggleMe = window.setInterval(refresh, 10000);
var currentPhraseID;

var wennGeladen = function () {
    allPhrases = JSON.parse(http.responseText);
    for (var i = 0; i < allPhrases.length; i++) {
        allPhrases[i].id = i;
        allPhrases[i].upvotes = 0;
        allPhrases[i].downvotes = 0;
        allPhrases[i].voted = 0;
        if (Array.isArray(allPhrases[i].category)) allPhrases[i].category.forEach(x => {
            if (!categories.includes(x)) categories.push(x);
        });
        else if (!categories.includes(allPhrases[i].category)) categories.push(allPhrases[i].category);
    }
    phrases = allPhrases;
    refresh();

}

function toggler() {
    toggleMe = !toggleMe;
    if (toggleMe == true) {
        document.getElementById('autoRefresh').src = 'img/timeron.png';
    } else {
        document.getElementById('autoRefresh').src = 'img/timeroff.png';
    }
}

function refresh() {
    var counter = 0;
    var checkRandom;
    var wait = function () {
        const randomNumber = Math.floor(Math.random() * phrases.length);
        document.getElementById('content').innerText = phrases[randomNumber].phrase;
        counter++;
        if (counter > 20) {
            window.clearInterval(setWait);
            currentPhraseID = phrases[randomNumber].id;
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
    //document.getElementById('rating').innerText = allPhrases[currentPhraseID].upvotes - allPhrases[currentPhraseID].downvotes; 
}

const http = new XMLHttpRequest();
http.open("GET", "obliqueStrats.json");
http.onload = wennGeladen;
http.send();