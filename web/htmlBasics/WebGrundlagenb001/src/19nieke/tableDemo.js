var quotes = null;

var wennGeladen = function () {
    quotes = JSON.parse(http.responseText);
    var table = null;
    quotes.forEach(q => {
        table = document.getElementById("quoteTable");
        const row = document.createElement("TR");
        const quote = document.createElement("TD");
        const name = document.createElement("TD");
        const tags = document.createElement("TD");

        quote.innerText = q.quote;
        name.innerText = q.author.name;
        tags.innerText = q.tags;

        row.appendChild(quote);
        row.appendChild(name);
        row.appendChild(tags);

        table.appendChild(row);
    });
}

const http = new XMLHttpRequest();
http.open("GET", "../data/quotes.json");
http.onload = wennGeladen;
http.send();