const table = document.getElementById("nolimit");
var quotes;
var row;
var cell1;
var cell2;
var cell3;
var reloader = false;
var sortCheck = 1;
var filterCalls = false;

function wennGeladen() {


    if (reloader == false && sortCheck == 1) {
        quotes = JSON.parse(http.responseText);

        insertTable();
        var zahl = 1;
        for (var index = 0; index <= quotes.length - 1; index++) {
            document.getElementById('zelle' + zahl + '1').innerHTML = quotes[index].quote;
            document.getElementById('zelle' + zahl + '2').innerHTML = quotes[index].author.name;
            document.getElementById('zelle' + zahl + '3').innerHTML = quotes[index].tags;
            zahl = zahl + 1;

        }


    } else if (sortCheck > 1) {

        insertTable();
        var zahl2 = 1;
        for (var index = 0; index <= quotes.length - 1; index++) {
            document.getElementById('zelle' + zahl2 + '1').innerHTML = quotes[index].quote;
            document.getElementById('zelle' + zahl2 + '2').innerHTML = quotes[index].author.name;
            document.getElementById('zelle' + zahl2 + '3').innerHTML = quotes[index].tags;
            zahl2 = zahl2 + 1;

        }

    } else if (filterCalls == true && reloader == true && sortCheck == 1) {
        insertTable();
        var zahl3 = 1;
        for (var index = 0; index <= quotes.length - 1; index++) {
            document.getElementById('zelle' + zahl3 + '1').innerHTML = quotes[index].quote;
            document.getElementById('zelle' + zahl3 + '2').innerHTML = quotes[index].author.name;
            document.getElementById('zelle' + zahl3 + '3').innerHTML = quotes[index].tags;
            zahl3 = zahl3 + 1;
        }
        filterCalls == false;
    }


}

function insertTable() {
    for (var x = 1; x <= quotes.length; x++) {
        row = table.insertRow(x);
        row.id = 'reihe' + x;
        cell1 = row.insertCell(0);
        cell1.id = 'zelle' + x + '1';
        cell2 = row.insertCell(1);
        cell2.id = 'zelle' + x + '2';
        cell3 = row.insertCell(2);
        cell3.id = 'zelle' + x + '3';
    }
}

function deleteTable() {

    while (document.getElementsByTagName("tr").length >= 1) {
        table.deleteRow(1);
        if (document.getElementsByTagName("tr").length == 1) {

            reloader = !reloader;
            wennGeladen();

            return;
        }
    }
}


function sortAuthor() {
    sortCheck++;
    if (reloader == false) {
        quotes.sort((a, b) => {
            return a.author.name.localeCompare(b.author.name);

        });

        deleteTable();


    } else if (reloader == true) {
        quotes.sort((a, b) => {
            return b.author.name.localeCompare(a.author.name);

        });

        deleteTable();



    }
}

function sortQuote() {
    sortCheck++;
    if (reloader == false) {
        quotes.sort((a, b) => {
            return a.quote.localeCompare(b.quote);

        });




        deleteTable();
    } else if (reloader == true) {
        quotes.sort((a, b) => {
            return b.quote.localeCompare(a.quote);

        });

        deleteTable();



    }
}

function sortTag() {
    sortCheck++;
    if (reloader == false) {
        quotes.sort((a, b) => {
            return a.tags[0].localeCompare(b.tags[0]);

        });




        deleteTable();
    } else if (reloader == true) {
        quotes.sort((a, b) => {
            return b.tags[0].localeCompare(a.tags[0]);

        });

        deleteTable();



    }

}

document.getElementById("input").onkeyup = function () {
    inputReader()
};

function inputReader() {
    var txtValue;
    var input = document.getElementById("input");
    var filter = input.value.toUpperCase();
    var table = document.getElementById("nolimit");
    var tr = table.getElementsByTagName("tr");
    for (var i = 1; i < tr.length; i++) {
        td = tr[i].getElementsByTagName("td")[0];
        td2 = tr[i].getElementsByTagName("td")[1];
        td3 = tr[i].getElementsByTagName("td")[2];
        if (td) {
            txtValue = td.textContent || td.innerText;
            txtValue2 = td2.textContent || td2.innerText;
            txtValue3 = td3.textContent || td3.innerText;
        }
        if (txtValue.toUpperCase().indexOf(filter) > -1 || txtValue2.toUpperCase().indexOf(filter) > -1 || txtValue3.toUpperCase().indexOf(filter) > -1) {
            tr[i].style.display = "";
        } else {
            tr[i].style.display = "none";
        }

    }
}



const http = new XMLHttpRequest();
http.open("GET", "../data/quotes.json");
http.onload = wennGeladen;
http.send()