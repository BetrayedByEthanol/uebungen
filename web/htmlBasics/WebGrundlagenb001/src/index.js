
var quotes = null;

var wennGeladen = function () {
    quotes = JSON.parse(http.responseText);

    const zitatElement = document.getElementById('zitat');
    const randomIndex = Math.floor(Math.random() * quotes.length);

    zitatElement.innerText = quotes[randomIndex].quote;

    const ausbilderquote = quotes.find(quote => quote.id == 'ausbilderquote');
    const petersquote = quotes.find(quote => quote.id == 'petersquote');
    
    const ausbilderquoteElement = document.getElementById('ausbilderquote');
    const ausbilderquoteAuthor = document.getElementById('ausbilderquoteAuthor');
    const petersquoteElement = document.getElementById('petersquote');
    const petersquoteAuthor = document.getElementById('petersquoteAuthor')



    ausbilderquoteElement.innerText = ausbilderquote.quote;
    ausbilderquoteAuthor.innerText = ausbilderquote.author.name;
    petersquoteElement.innerText = petersquote.quote;
    petersquoteAuthor.innerText = petersquote.author.name;
}

const http = new XMLHttpRequest();
http.open("GET", "data/quotes.json");
http.onload = wennGeladen;
http.send()