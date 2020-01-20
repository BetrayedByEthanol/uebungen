var phrases;
var randomNumber;
const htmlElement;
var timer = 0;

var wennGeladen = function () 
{
    phrases = JSON.parse(http.responseText);
    randomNumber = Math.floor(Math.random() * phrashes.length);
    htmlElement = document.getElementById('Main'); 
    htmlElement.innterText = phrases[randomNumber].phrase; 

    // while(true)
    // {
    //     timer += 10;
    //     window.setTimeout(10);
    //     if(timer >= 60000) refresh();
    // }
}

function refresh()
{
    randomNumber =  Math.floor(Math.random() * phrashes.length);
    htmlElement.innterText = phrases[randomNumber].phrase;
    timer = 0; 
}

const http = new XMLHttpRequest();
http.open("GET", "cklauß/obliqueStrats.json");
http.onload = wennGeladen;
http.send();