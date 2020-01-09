
var quotes = null;

var wennGeladen = function () {
    quotes = JSON.parse(http.responseText);

    const zitatElement = document.getElementById('zitat');
    const randomIndex = Math.floor(Math.random() * quotes.length);

    zitatElement.innerText = quotes[randomIndex].quote;

    const ausbilderquote = quotes.find(quote => quote.author.age == 'ausbilderquote');
    
    const ausbilderquoteElement = document.getElementById('ausbilderquote');
    const ausbilderquoteAuthor = document.getElementById('ausbilderquoteAuthor');

    ausbilderquoteElement.innerText = ausbilderquote.quote;
    ausbilderquoteAuthor.innerText = ausbilderquote.author.name;
}

const http = new XMLHttpRequest();
http.open("GET", "data/quotes.json");
http.onload = wennGeladen;
http.send()