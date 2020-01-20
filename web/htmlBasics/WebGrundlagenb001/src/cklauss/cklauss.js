var phrases;
var allPhrases;
var randomNumber;
var timer = 0;

var wennGeladen = function () {
    allPhrases = JSON.parse(http.responseText);
    phrases = allPhrases;
    refresh();

    const autoRefresh = function () {
        timer += 100;
        if (timer >= 60000) refresh();
    }
    window.setInterval(autoRefresh, 100);
}

function refresh() {
    randomNumber = Math.floor(Math.random() * phrases.length);
    document.getElementById('content').innerText = phrases[randomNumber].phrase;
    timer = 0;
}

function filterPhrases(category) {
    phrases = allPhrases.filter(p => { return p.category == category })
}

const http = new XMLHttpRequest();
http.open("GET", "obliqueStrats.json");
http.onload = wennGeladen;
http.send();