var phrases;
var randomNumber;
var timer = 0;

var wennGeladen = function () 
{
    phrases = JSON.parse(http.responseText);
    randomNumber = Math.floor(Math.random() * phrases.length);
    document.getElementById('main').innerText = phrases[randomNumber].phrase; 

    const autoRefresh =  function() 
    {
        timer += 100;
        if(timer >= 60000) refresh();
    }
    window.setInterval(autoRefresh,100);
}

function refresh()
{
    randomNumber =  Math.floor(Math.random() * phrases.length);
    document.getElementById('main').innerText = phrases[randomNumber].phrase;
    timer = 0; 
}

const http = new XMLHttpRequest();
http.open("GET", "obliqueStrats.json");
http.onload = wennGeladen;
http.send();