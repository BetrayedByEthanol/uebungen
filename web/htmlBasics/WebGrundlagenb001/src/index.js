
var quotes = null;

var wennGeladen = function () {
    quotes = JSON.parse(http.responseText);

    const zitatElement = document.getElementById('zitat');
    const randomIndex = Math.floor(Math.random() * quotes.length);
    zitatElement.innerText = quotes[randomIndex].quote;

    const gruppe = ["ausbilder", "19adam", "19behm", "19nieke", "19peters", "19poeppmann", "19rose", "19seifert", "19soler", "19tantsch", "19zech"];

    gruppe.forEach(teilnehmer => {

        const quoteID = teilnehmer + 'quote';
        const quote  = quotes.find(quote => quote.id == quoteID);
        const quoteElement = document.getElementById(quoteID);
        const quoteAuthorElement = document.getElementById(quoteID + 'Author');
      
        if (quote && quoteElement && quoteAuthorElement) {
            quoteElement.innerText = quote.quote ;
            quoteAuthorElement.innerText = quote.author.name;
        };

    });

}

const http = new XMLHttpRequest();
http.open("GET", "data/quotes.json");
http.onload = wennGeladen;
http.send()