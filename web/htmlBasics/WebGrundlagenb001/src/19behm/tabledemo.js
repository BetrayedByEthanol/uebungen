function sortTable(n) {
    var table, rows, switching, i, x, y, shouldSwitch, dir, switchcount = 0;
    table = document.getElementById("quotetable");
    switching = true;
    dir = "asc";

    while (switching) {
        switching = false;
        rows = table.rows;
        for (i = 2; i < (rows.length - 1); i++) {
            shouldSwitch = false;
            x = rows[i].getElementsByTagName('td')[n];
            y = rows[i + 1].getElementsByTagName('td')[n];
            if (dir == "asc") {
                if (x.innerHTML.toLowerCase() > y.innerHTML.toLowerCase()) {
                    shouldSwitch = true;
                    break
                }
            } else if (dir == "desc") {
                if (x.innerHTML.toLowerCase() < y.innerHTML.toLowerCase()) {
                    shouldSwitch = true;
                    break;
                }
            }
        }
        if (shouldSwitch) {
            rows[i].parentNode.insertBefore(rows[i + 1], rows[i]);
            switching = true;
            switchcount++;
        } else {
            if (switchcount == 0 && dir == "asc") {
                dir = "desc";
                switching = true;
            }
        }
    }
}

function filterTable() {
    var input , filter, table, tr, td,i,txtValue;
    input = document.getElementById("searchinput");
    filter = input.value.toUpperCase();
    table = document.getElementById("quotetable");
    tr = table.getElementsByTagName("tr");

    for (i=0;i<tr.length;i++) {
        td = tr[i].getElementsByTagName("td")[0];
        if(td) {
            txtValue = td.textContent || td.innerText;
            if(txtValue.toUpperCase().indexOf(filter) > -1){
                tr[i].style.display = "";
            } else {
                tr[i].style.display = "none";
            }
        }
    }
}


function createtable() {

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