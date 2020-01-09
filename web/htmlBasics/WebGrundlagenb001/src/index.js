
var quotes = null;

var wennGeladen = function () {
    quotes = JSON.parse(http.responseText);

    const zitatElement = document.getElementById('zitat');
    const randomIndex = Math.floor(Math.random() * quotes.length);
    zitatElement.innerText = quotes[randomIndex].quote;

    const ausbilderquote = quotes.find(quote => quote.id == 'ausbilderquote');
    const niekequote = quotes.find(quote => quote.id == '19niekequote');
    const zechquote = quotes.find(quote => quote.author == 'zechquote');
    
    const ausbilderquoteElement = document.getElementById('ausbilderquote');
    const ausbilderquoteAuthor = document.getElementById('ausbilderquoteAuthor');
    const niekequoteElement = document.getElementById('19niekequote');
    const niekequoteAuthor = document.getElementById('19niekeAuthor');    
    const zechquoteElement = document.getElementById('19zechquote');
    const zechquoteAuthor = document.getElementById('19zechquoteAuthor');

    ausbilderquoteElement.innerText = ausbilderquote.quote;
    ausbilderquoteAuthor.innerText = ausbilderquote.author.name;
    niekequoteElement.innerText = niekequote.quote;
    niekequoteAuthor.innerText = niekequote.author.name;

}

const http = new XMLHttpRequest();
http.open("GET", "data/quotes.json");
http.onload = wennGeladen;
http.send()