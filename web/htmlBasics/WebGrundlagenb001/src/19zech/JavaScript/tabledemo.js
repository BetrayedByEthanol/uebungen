var initialLoad = 0;
var sortedAuthor = 0;

var loaded = function() {
  if (initialLoad == 0 || sortedAuthor == 2 || sortedQuote == 2) {
    quoteID = JSON.parse(http.responseText);
    createTable();
    sortedAuthor = 0;
    sortedQuote = 0;
  } else if (initialLoad != 0 && sortedAuthor == 1) {
    quoteID.sort(compareAuthor);
    createTable(quoteID.sort(compareAuthor));
  } else if (initialLoad != 0 && sortedQuote == 1) {
    quoteID.sort(compareAlphabetically);
    createTable();
  }
};
function sortQuote() {
  sortedQuote++;
  initialLoad = 1;
  deleteStuff();
  loaded();
}
function sortAuthor() {
  sortedAuthor++;
  initialLoad = 1;
  deleteStuff();
  loaded();
}
function createTable() {
  quoteID.forEach(participant => {
    quotes = document.getElementById("fuckthis");
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
  });
}
function compareAuthor(quoteA, quoteB) {
  if (quoteB.author.name.toLowerCase() > quoteA.author.name.toLowerCase()) {
    return -1;
  }
  if (quoteA.author.name.toLowerCase() > quoteB.author.name.toLowerCase()) {
    return 1;
  }
  return 0;
}
function compareAlphabetically(quoteA, quoteB) {
  if (quoteB.quote.toLowerCase() > quoteA.quote.toLowerCase()) {
    return -1;
  }
  if (quoteA.quote.toLowerCase() > quoteB.quote.toLowerCase()) {
    return 1;
  }
  return 0;
}
function deleteStuff() {
  var table = document.getElementById("fuckthis");

  while (document.getElementsByTagName("TR").length > 1) {
    table.deleteRow(1);
    if (document.getElementsByTagName("TR").length == 0) {
      return;
    }
  }
}
function filterStuff() {
  var input, filter, tr, td,td2, td3, i, textValue, textValue2, textValue3;
  input = document.getElementById("searchID");
  filter = input.value.toUpperCase();
  table = document.getElementById("fuckthis");
  tr = document.getElementsByTagName("tr");

  for(i=0; i< tr.length; i++) {
    td = tr[i].getElementsByTagName("td")[0];
    td2 = tr[i].getElementsByTagName("td")[1];
    td3 = tr[i].getElementsByTagName("td")[2]
    if(td) {
      textValue = td.textContent || td.innerText;
      textValue2 = td2.textContent || td2.innerText;
      textValue3 = td3.textContent || td3.innerText;
      if(textValue.toUpperCase().indexOf(filter) > -1 || textValue2.toUpperCase().indexOf(filter) > -1 || textValue3.toUpperCase().indexOf(filter) > -1) {
        tr[i].style.display = "";
      } else {
        tr[i].style.display = "none";
      }
    }
  }
}



const http = new XMLHttpRequest();
http.open("GET", "../data/quotes.json");
http.onload = loaded;
http.send();