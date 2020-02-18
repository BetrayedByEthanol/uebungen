var phrases;
var allPhrases;
var categories = [];
var toggleMe = false;
var autoRefresh;
var currentPhraseID;

var wennGeladen = function () {
    allPhrases = JSON.parse(http.responseText);
    for (var i = 0; i < allPhrases.length; i++) {
        allPhrases[i].id = i;
        allPhrases[i].category.forEach(x => {
            if (!categories.includes(x)) categories.push(x);
        });
    }
    phrases = allPhrases;
    refresh();
    
}

function toggler() {
    toggleMe = !toggleMe;
    if (toggleMe == true) {
        autoRefresh = window.setInterval(refresh, 10000);
        document.getElementById('autoRefresh').src = 'img/timeron.png';
    } else {
        document.getElementById('autoRefresh').src = 'img/timeroff.png';
        window.clearInterval(autoRefresh);
    }
}

function refresh() {
    var counter = 0;
    var wait = function () {
        const randomNumber = Math.floor(Math.random() * phrases.length);
        document.getElementById('content').innerText = phrases[randomNumber].phrase;
        counter++;
        if (counter > 20) {
            window.clearInterval(setWait);
            currentPhraseID = phrases[randomNumber].id;
            currentPhraseMongoID = phrases[randomNumber]._id;
            document.getElementById('category').innerText = phrases[randomNumber].category;
            try{
                ColorChange();
            } catch(err){
                console.log(err);
            }
            getRating();          
            document.getElementById('category').innerText = "Category: " + phrases[randomNumber].category;

        }

    }
    fetch('/strategy/' , {
        method: "GET"
    }).then(res => {
        console.log(res.text());
    });

    var setWait = window.setInterval(wait, 40);
    
}

function filterPhrases(category) {
    phrases = allPhrases.filter(p => { return p.category == category });
}

function ColorChange(){
    const theme = document.getElementById("category").innerText;
    if(theme == "Growth"){
        document.getElementById("jumbo").className = "jumbotron bg-success mh-100";
        document.getElementById("content").className = "display-5 text-break text-light";
        document.getElementById("category").className = "lead text-right text-light";
    }
    else if(theme == "New Perspective"|| theme == "Self-Care,New Perspective,Philosophical"){
        document.getElementById("jumbo").className = "jumbotron bg-secondary mh-100";
        document.getElementById("content").className = "display-5 text-break text-light";
        document.getElementById("category").className = "lead text-right text-light";  
    }
    else if(theme =="Programming" ||theme == "Philosophy" || theme == "Philosophical" || theme == "Philosophical,Programming,Self-Confidence,New Perspective"){
        document.getElementById("jumbo").className = "jumbotron bg-warning mh-100";
        document.getElementById("content").className = "display-5 text-break text-dark";
        document.getElementById("category").className = "lead text-right text-dark";
    }
    else if(theme == "Technology" || theme == "Technology,New Perspective"){
        document.getElementById("jumbo").className = "jumbotron bg-info mh-100";
        document.getElementById("content").className = "display-5 text-break text-light";
        document.getElementById("category").className = "lead text-right text-light";
    }
    else if(theme == "Self-Confidence" || theme == "Self-Care" ){
        document.getElementById("jumbo").className = "jumbotron bg-danger mh-100";
        document.getElementById("content").className = "display-5 text-break text-dark";
        document.getElementById("category").className = "lead text-right text-dark";
    }
    else if(theme == "Technology"){
        document.getElementById("jumbo").className = "jumbotron bg-light mh-100";
        document.getElementById("content").className = "display-5 text-break text-dark";
        document.getElementById("category").className = "lead text-right text-dark";
    }
    else
    {
        document.getElementById("jumbo").className = "jumbotron bg-dark mh-100";
        document.getElementById("content").className = "display-5 text-break text-light";
        document.getElementById("category").className = "lead text-right text-light";
    }
}

function vote(vote) {
    if (vote == 1 && allPhrases[currentPhraseID].voted == 0) {
        allPhrases[currentPhraseID].upvotes++;
        allPhrases[currentPhraseID].voted = 1;
        document.getElementById('downvote').style.visibility = 'hidden';
    } else if (vote == 0 && allPhrases[currentPhraseID].voted == 0) {
        allPhrases[currentPhraseID].downvotes++;
        allPhrases[currentPhraseID].voted = -1;
        document.getElementById('upvote').style.visibility = 'hidden';
    } else if (allPhrases[currentPhraseID].voted == 1) {
        allPhrases[currentPhraseID].upvotes--;
        allPhrases[currentPhraseID].voted = 0;

    } else {
        allPhrases[currentPhraseID].downvotes--;
        allPhrases[currentPhraseID].voted = 0;

    }
    getRating();
}

function getRating() {
    if (allPhrases[currentPhraseID].votes.length == 0) {
        document.getElementById('upvote').style.visibility = 'visible';
        document.getElementById('downvote').style.visibility = 'visible';
    } else if (allPhrases[currentPhraseID].votes[0].status == 1) {
        document.getElementById('upvote').style.visibility = 'visible';
        document.getElementById('downvote').style.visibility = 'hidden';
    } else {
        document.getElementById('upvote').style.visibility = 'hidden';
        document.getElementById('downvote').style.visibility = 'visible';
    }
    document.getElementById('rating').innerText = allPhrases[currentPhraseID].rating;
}

function vote(param) {
    if (allPhrases[currentPhraseID].votes.length != 0) {
        param = '/unvote';
        (allPhrases[currentPhraseID].votes[0].status == 1)? allPhrases[currentPhraseID].rating-- : allPhrases[currentPhraseID].rating++;
        allPhrases[currentPhraseID].votes = [];
    } else if(param.includes('upvote')){
        allPhrases[currentPhraseID].rating++;
        var status = 1
        allPhrases[currentPhraseID].votes.push(status);
    } else {
        allPhrases[currentPhraseID].rating--;
        var status = -1
        allPhrases[currentPhraseID].votes.push(status);
    }

    fetch('/strategies/' + allPhrases[currentPhraseID]._id + param, {
        method: "POST"
    }).then(res => {
        console.log(res.text());
    });
    getRating();
}

const http = new XMLHttpRequest();
http.open("GET", "/strategy");
http.onload = wennGeladen;
http.send();