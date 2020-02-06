function gentable(){

    quotes = JSON.parse(request.responseText);
    var table = document.getElementById('doctable');

    quotes.forEach(element => {
        var newrow = document.createElement('tr');

        /*var newel = document.createElement('td');*/

        var newquote = document.createElement('td');
        var newauthor = document.createElement('td');
        var newage = document.createElement('td');
        var newid = document.createElement('td');

        var quote = document.createTextNode(element.quote);
        var author = document.createTextNode(element.author.name);
        var age = document.createTextNode(element.author.age);
        var id = document.createTextNode(element.id);

        table.appendChild(newrow);

        newrow.appendChild(newquote);
        newrow.appendChild(newauthor);
        newrow.appendChild(newage);
        newrow.appendChild(newid);


        newquote.appendChild(quote);
        newauthor.appendChild(author);
        newage.appendChild(age);
        newid.appendChild(id);
        
    })

}

function sortby(n){

    var x, y, i, table, tablerows, switchbool, shouldswitch;
    table = document.getElementById('doctable');

    switchbool = true;

    while(switchbool){

        tablerows = table.rows;
        switchbool = false;

        for(i = 1; i < (tablerows.length - 1); i++){

            x = tablerows[i].getElementsByTagName('td')[n];
            y = tablerows[i + 1].getElementsByTagName('td')[n];

            /*console.log(x);
            console.log(y);*/

            if(x.innerText.toLowerCase() < y.innerText.toLowerCase()){

                shouldswitch = true;
                break;

            }

        }

        if(shouldswitch){

            tablerows[i].parentNode.insertBefore(tablerows[i + 1], tablerows[i]);
            shouldswitch = false;
            switchbool = true;

        }

    }

}

var request = new XMLHttpRequest();
request.open("GET", "../data/quotes.json");
request.onload = gentable;
request.send();

/*document.getElementById('but1').addEventListener('click', sortby(1));
document.getElementById('but2').addEventListener('click', sortby(2));
document.getElementById('but3').addEventListener('click', sortby(3));*/
