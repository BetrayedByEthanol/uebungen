
var strategies = null;

var loaded = function () {
    strategies = JSON.parse(http.responseText);

    strategies.forEach(element => {
        const block = document.getElementById("dummyCard");
        const newBlock = block.cloneNode(true);
        newBlock.getElementsByTagName('div')[0].innerText = element.phrase;
        newBlock.hidden = false;
        newBlock.getElementsByTagName('div')[1].innerText = element.category;
        newBlock.getElementsByTagName('div')[2].innerText = element.upvotes - element.downvotes ;
        

        const card = document.getElementById("card");
        card.appendChild(newBlock);
        
    });
}








const http = new XMLHttpRequest();
http.open("GET", "/strategies");
http.onload = loaded;
http.send();