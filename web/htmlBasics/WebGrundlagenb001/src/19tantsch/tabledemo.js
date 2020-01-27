

function wennGeladen(){
var quotes = JSON.parse(http.responseText);


var table = document.getElementById("nolimit");


quotes.forEach(zeile => {
var row = table.insertRow(1);

var cell1 = row.insertCell(0);
var cell2 = row.insertCell(1);
var cell3 = row.insertCell(2);

cell1.innerHTML = zeile.quote;
cell2.innerHTML = zeile.author.name;
cell3.innerHTML = zeile.tags;
    
});

}

const http = new XMLHttpRequest();
http.open("GET", "../data/quotes.json");
http.onload = wennGeladen;
http.send()



