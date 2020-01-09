
var zitat = document.getElementById('zitat');
var quotes = null;

var wennGeladen = function () {
    quotes = JSON.parse(http.responseText);

    const zitat = document.getElementById('zitat');
    zitat.innerText = quotes[0].quote;

    const ausbilderquote = quotes.find(quote => quote.id == 'ausbilderquote');

    const ausbilderquoteElement = document.getElementById('ausbilderquote');
    const ausbilderquoteAuthor = document.getElementById('ausbilderquoteAuthor');
    
    ausbilderquoteElement.innerText = ausbilderquote.quote;
    ausbilderquoteAuthor.innerText = ausbilderquote.author.name;
}

const http = new XMLHttpRequest();
http.open("GET", "data/quotes.json");
http.onload = wennGeladen;
http.send()