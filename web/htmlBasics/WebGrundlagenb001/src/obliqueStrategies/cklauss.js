var phrases;
var allPhrases;
var timer = 0;
var categories = [];
var einaus = false;
var toggleMe = window.setInterval(refresh, 10000);



var wennGeladen = function () {
    allPhrases = JSON.parse(http.responseText);
    phrases = allPhrases;
    refresh();
    allPhrases.forEach(p => {
        if (Array.isArray(p.category)) p.category.forEach(x => {
            if (!categories.includes(x)) categories.push(x);
        });
        else if(!categories.includes(p.category)) categories.push(p.category);
    });
}


function toggler(){
    if(einaus == false){ 
        clearInterval(toggleMe);
        einaus = true;
    }
    else if(einaus == true){
        toggleMe = window.setInterval(refresh, 10000);        
        einaus = false;
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