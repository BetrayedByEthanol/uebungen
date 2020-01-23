var phrases;
var allPhrases;
var timer = 0;
var categories = [];
var toggleMe = false;


var wennGeladen = function () {
    allPhrases = JSON.parse(http.responseText);
    phrases = allPhrases;
    refresh();
    //const toggleMe = document.getElementById("toToggle");
    allPhrases.forEach(p => {
        if (Array.isArray(p.category)) p.category.forEach(x => {
            if (!categories.includes(x)) categories.push(x);
        });
        else if(!categories.includes(p.category)) categories.push(p.category);
    });

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
    timer = 0;
}

function filterPhrases(category) {
    phrases = allPhrases.filter(p => { return p.category == category });
}

const http = new XMLHttpRequest();
http.open("GET", "obliqueStrats.json");
http.onload = wennGeladen;
http.send();