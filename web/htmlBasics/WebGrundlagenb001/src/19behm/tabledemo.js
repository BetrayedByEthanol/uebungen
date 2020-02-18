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
    var input , filter, table, tr, td1,td2,td3,i,txtValue1,txtValue2,txtValue3;
    input = document.getElementById("searchinput");
    filter = input.value.toUpperCase();
    table = document.getElementById("quotetable");
    tr = table.getElementsByTagName("tr");

    for (i=0;i<tr.length;i++) {
        td1 = tr[i].getElementsByTagName("td")[0];
        td2 = tr[i].getElementsByTagName("td")[1];
        td3 = tr[i].getElementsByTagName("td")[2];
        if(td1) {
            txtValue1 = td1.textContent || td1.innerText;
            txtValue2 = td2.textContent || td2.innerText;
            txtValue3 = td3.textContent || td3.innerText;
            if(txtValue1.toUpperCase().indexOf(filter) > -1 || txtValue2.toUpperCase().indexOf(filter)> -1 || txtValue3.toUpperCase().indexOf(filter) > -1){
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
tablerequest.open("GET", 'http://10.42.53.5:5050/strategies');
tablerequest.onload = createtable;
tablerequest.send();