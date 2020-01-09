
var quotes = null;

var wennGeladen = function () {
    quotes = JSON.parse(http.responseText);

    const zitatElement = document.getElementById('zitat');
    const randomIndex = Math.floor(Math.random() * quotes.length);
    zitatElement.innerText = quotes[randomIndex].quote;
<<<<<<< HEAD
    
=======

>>>>>>> 11192a36792e80e07633f97055106ec2e9c0138f
    const ausbilderquote = quotes.find(quote => quote.id == 'ausbilderquote');
    const niekequote = quotes.find(quote => quote.id == '19niekequote');
    const zechquote = quotes.find(quote => quote.id == '19zechquote');
    
    const petersquote = quotes.find(quote => quote.id == 'petersquote');
    
    const ausbilderquoteElement = document.getElementById('ausbilderquote');
    const ausbilderquoteAuthor = document.getElementById('ausbilderquoteAuthor');
    const niekequoteElement = document.getElementById('19niekequote');
<<<<<<< HEAD
    const niekequoteAuthor = document.getElementById('19niekeAuthor');   


    const petersquoteElement = document.getElementById('petersquote');
    const petersquoteAuthor = document.getElementById('petersquoteAuthor') 
=======
    const niekequoteAuthor = document.getElementById('19niekeAuthor');    
    const zechquoteElement = document.getElementById('19zechquote');
    const zechquoteAuthor = document.getElementById('19zechquoteAuthor');
>>>>>>> 11192a36792e80e07633f97055106ec2e9c0138f

    ausbilderquoteElement.innerText = ausbilderquote.quote;
    ausbilderquoteAuthor.innerText = ausbilderquote.author.name;
    niekequoteElement.innerText = niekequote.quote;
    niekequoteAuthor.innerText = niekequote.author.name;
    zechquoteElement.innerText = zechquote.quote;
    zechquoteAuthor.innerText = zechquote.author.name;


    petersquoteElement.innerText = petersquote.quote;
    petersquoteAuthor.innerText = petersquote.author.name;

}

const http = new XMLHttpRequest();
http.open("GET", "data/quotes.json");
http.onload = wennGeladen;
http.send()