

function createtable(){

    quotes = JSON.parse(tablerequest.responseText);
    var table = document.getElementById('quotetable');
    quotes.forEach(element => {
        var row = document.createElement('tr');
        var dataQuote = document.createElement('td');
        var dataAuthor = document.createElement('td');
        var dataTags = document.createElement('td');
        
        var textQuote = document.createTextNode(element.quote);
        var textAuthor = document.createTextNode(element.author.name);
        var textTags = document.createTextNode(element.tags);

        dataQuote.appendChild(textQuote);
        dataAuthor.appendChild(textAuthor);
        dataTags.appendChild(textTags);

        row.appendChild(dataQuote);
        row.appendChild(dataAuthor);
        row.appendChild(dataTags);
        table.appendChild(row);
    });
    
    
}

var tablerequest = new XMLHttpRequest();
tablerequest.open("GET", "../data/quotes.json");
tablerequest.onload = createtable;
tablerequest.send();
