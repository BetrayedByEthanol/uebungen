var quotes = null;
var namesort = 0;
var gruppe = ["19ausbilder", "19adam", "19behm", "19nieke", "19peters", "19poeppmann", "19rose", "19seifert", "19soler", "19tantsch", "19zech"];

var wennGeladen = function () {
    quotes = JSON.parse(http.responseText);

    // const zitatElement = document.getElementById('zitat');
    // const randomIndex = Math.floor(Math.random() * quotes.length);
    // zitatElement.innerText = quotes[randomIndex].quote;


    gruppe.forEach(teilnehmer => {

        const block = document.getElementById('applepie');
        const newBlock = block.cloneNode(true);
        newBlock.id = 'nameID';
        
        newBlock.getElementsByTagName('h2')[0].innerText = teilnehmer;
        // newBlock.getElementsByTagName('image')[0].setAttribute('href', '../img/' + teilnehmer + 'profile.png');
        // newBlock.getElementsByTagName('a')[0].setAttribute('href', teilnehmer + 'profil.html');
       
        const quoteID = teilnehmer + 'quote';
        const quote = quotes.find(quote => quote.id == quoteID);
     
        if (quote) {
            newBlock.getElementsByTagName('span')[0].innerText = quote.quote;
            newBlock.getElementsByTagName('span')[1].innerText = quote.author.name;
        };
        const row = document.getElementById('row');
        row.appendChild(newBlock);
        newBlock.hidden = false;

    });
}

function sort_name() {
    var hgf = document.getElementsByClassName('th1');
    for (i in gruppe) {
        var kl = document.getElementById('nameID')
        kl.remove();
    }
    gruppe.sort();
    if (namesort == 1) {
        gruppe.reverse();
        namesort = 0;
    }
    else namesort = 1;
    wennGeladen();
}

const http = new XMLHttpRequest();
http.open("GET", "../data/quotes.json");
http.onload = wennGeladen;
http.send()