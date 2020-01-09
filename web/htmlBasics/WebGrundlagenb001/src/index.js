
var quotes = null;

var wennGeladen = function () {
    quotes = JSON.parse(http.responseText);

    const zitatElement = document.getElementById('zitat');
    const randomIndex = Math.floor(Math.random() * quotes.length);

    zitatElement.innerText = quotes[randomIndex].quote;

    const ausbilderquote = quotes.find(quote => quote.id == 'ausbilderquote');
    
    const ausbilderquoteElement = document.getElementById('ausbilderquote');
    const ausbilderquoteAuthor = document.getElementById('ausbilderquoteAuthor');

    const zechquote = quotes.find(quote => quote.author == 'zechquote');

    const zechquoteElement = document.getElementById('zechquote');
    const zechquoteAuthor = document.getElementById('zechquoteAuthor');

    ausbilderquoteElement.innerText = ausbilderquote.quote;
    ausbilderquoteAuthor.innerText = ausbilderquote.author.name;
}

const http = new XMLHttpRequest();
http.open("GET", "data/quotes.json");
http.onload = wennGeladen;
http.send()