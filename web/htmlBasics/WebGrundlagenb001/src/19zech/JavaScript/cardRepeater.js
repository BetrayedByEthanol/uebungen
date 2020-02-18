var strategies = null;

var loaded = function() {
    obliqueID = JSON.parse(http.responseText);
    
    var table = null;
    strategies = document.getElementById('cardID');
    obliqueID.forEach(strategy => {

        
        console.log(strategy.phrase);

        const card = document.createElement("DIV");
        card.className = "card container";
        card.id = "cardID";

        const phrase = document.createElement("DIV");
        phrase.className = "item-content font";
        phrase.id = "content";
        const rating = document.createElement("DIV");
        rating.className = "item-rating";
        rating.id = "rating";
        const category = document.createElement("DIV");
        category.className = "item-category";
        category.id = "rating";

        strategies.innerText = strategy.phrase;
        rating.innerText = strategy.rating;
        category.innerText = strategy.category;

        card.appendChild(phrase);
        card.appendChild(rating);
        card.appendChild(category);

        strategies.appendChild(card);
    })
}

const http = new XMLHttpRequest();
http.open("GET", "obliqueStrats.json");
http.onload = loaded;
http.send()