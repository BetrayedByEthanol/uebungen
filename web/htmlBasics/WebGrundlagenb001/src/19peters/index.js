var quotes = null;

var wennGeladen = function () {
    quotes = JSON.parse(http.responseText);

    // const zitatElement = document.getElementById('zitat');
    // const randomIndex = Math.floor(Math.random() * quotes.length);
    // zitatElement.innerText = quotes[randomIndex].quote;

    const gruppe = ["ausbilder", "19adam", "19behm", "19nieke", "19peters", "19poeppmann", "19rose", "19seifert", "19soler", "19tantsch", "19zech"];

    gruppe.forEach(teilnehmer => {

        const block = document.getElementById('applepie');
        const newBlock = block.cloneNode(true);
        newBlock.id = teilnehmer + 'nameID';
        
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

const http = new XMLHttpRequest();
http.open("GET", "../data/quotes.json");
http.onload = wennGeladen;
http.send()