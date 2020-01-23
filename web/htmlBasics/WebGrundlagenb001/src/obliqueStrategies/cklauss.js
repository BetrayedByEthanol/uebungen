var phrases;
var allPhrases;
var timer = 0;
var categories = [];
var toggleMe = false;
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
    //const toggleMe = document.getElementById("toToggle");

    window.setInterval(autoRefresh => {
        timer += 100;
        if (timer >= 5000 && toggleMe) refresh();
    }, 100);
}

function toggle() {
    toggleMe = !toggleMe;
    if(toggleMe == true) {
        document.getElementById('autoRefresh').src ='img/timeron.png';
    } else {
        document.getElementById('autoRefresh').src ='img/timeroff.png';
    }
}

function refresh() {
    const randomNumber = Math.floor(Math.random() * phrases.length);
    document.getElementById('content').innerText = phrases[randomNumber].phrase;
    document.getElementById('category').innerText = phrases[randomNumber].category;
    currentPhraseID = phrases[randomNumber].id;
    getRating();
    timer = 0;
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