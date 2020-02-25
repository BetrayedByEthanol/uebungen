var phrases;
var categories = [];
var toggleMe = false;
var autoRefresh;
var currentPhraseID;

function toggler() {
    toggleMe = !toggleMe;
    if (toggleMe == true) {
        autoRefresh = window.setInterval(loadData, 10000);
        document.getElementById('autoRefresh').src = 'img/timeronb.png';
    } else {
        document.getElementById('autoRefresh').src = 'img/timeroffb.png';
        window.clearInterval(autoRefresh);
    }
}

function loadData() {
    fetch('/strategy/', { method: "GET" })
        .then(res => res.json())
        .then(data => {
            phrases = data;
            for (var i = 0; i < phrases.length; i++) {
                phrases[i].id = i;
                phrases[i].category.forEach(x => {
                    if (!categories.includes(x)) categories.push(x);
                });
            }
        });
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
            getRating();
            document.getElementById('category').innerText = "Category: " + phrases[randomNumber].category;
        }
    }
    var setWait = window.setInterval(wait, 40);
}


function getRating() {
    if (phrases[currentPhraseID].votes.length == 0) {
        document.getElementById('upvote').style.visibility = 'visible';
        document.getElementById('downvote').style.visibility = 'visible';
    } else if (phrases[currentPhraseID].votes[0].status == 1) {
        document.getElementById('upvote').style.visibility = 'visible';
        document.getElementById('downvote').style.visibility = 'hidden';
    } else {
        document.getElementById('upvote').style.visibility = 'hidden';
        document.getElementById('downvote').style.visibility = 'visible';
    }
    document.getElementById('rating').innerText = phrases[currentPhraseID].rating;
}

function vote(param) {
    if (phrases[currentPhraseID].votes.length != 0) {
        param = '/unvote';
        (phrases[currentPhraseID].votes[0].status == 1) ? phrases[currentPhraseID].rating-- : phrases[currentPhraseID].rating++;
        phrases[currentPhraseID].votes = [];
    } else if (param.includes('upvote')) {
        phrases[currentPhraseID].rating++;
        let vote = {
            status: 1
        }
        phrases[currentPhraseID].votes.push(vote);
    } else {
        phrases[currentPhraseID].rating--;
        let vote = {
            status: -1
        }
        phrases[currentPhraseID].votes.push(vote);
    }
    fetch('/strategies/' + phrases[currentPhraseID]._id + param, {
        method: "POST"
    }).then(res => {
        console.log(res.text());
    });
    getRating();
}
window.onload = loadData;