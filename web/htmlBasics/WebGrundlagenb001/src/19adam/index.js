function gentable(){

    quotes = JSON.parse(request.responseText);
    var table = document.getElementById('doctable');

    quotes.forEach(element => {
        var newrow = document.createElement('tr');

        /*var newel = document.createElement('td');*/

        var newquote = document.createElement('td');
        var newauthor = document.createElement('td');
        var newage = document.createElement('td');

        var quote = document.createTextNode(element.quote);
        var author = document.createTextNode(element.author.name);
        var age = document.createTextNode(element.author.age);

        table.appendChild(newrow);

        newrow.appendChild(newquote);
        newrow.appendChild(newauthor);
        newrow.appendChild(newage);


        newquote.appendChild(quote);
        newauthor.appendChild(author);
        newage.appendChild(age);
        
    })

}

var request = new XMLHttpRequest();
request.open("GET", "../data/quotes.json");
request.onload = gentable;
request.send();
