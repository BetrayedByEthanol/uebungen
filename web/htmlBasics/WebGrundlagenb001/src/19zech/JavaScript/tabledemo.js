var quotes = null;

var loaded = function() {
    quoteID = JSON.parse(http.responseText);
    
    var table = null;

    quoteID.forEach(participant => {

        quotes = document.getElementById('fuckthis');
        const row = document.createElement("TR");
        const quote = document.createElement("TD");
        const name = document.createElement("TD");
        const tags = document.createElement("TD");

        quote.innerText = participant.quote;
        name.innerText = participant.author.name;
        tags.innerText = participant.tags;

        row.appendChild(quote);
        row.appendChild(name);
        row.appendChild(tags);

        quotes.appendChild(row);
    })
    

}

const http = new XMLHttpRequest();
http.open("GET", "../data/quotes.json");
http.onload = loaded;
http.send()