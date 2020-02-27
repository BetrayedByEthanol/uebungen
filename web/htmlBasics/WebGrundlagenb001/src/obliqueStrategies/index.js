var phrases;
var autoRefresh = false;

function toggler() {
    if (autoRefresh == false) {
        autoRefresh = window.setInterval(loadData, 10000);
        document.getElementById('autoRefresh').src = 'img/timeron.png';
    } else {
        document.getElementById('autoRefresh').src = 'img/timeroff.png';
        window.clearInterval(autoRefresh);
        autoRefresh = false;
    }
}

function loadData() {
    fetch('/strategySample/', { method: "GET" })
        .then(res => res.json())
        .then(data => {
            phrases = data;
        });
    var counter = 0;
    var animation = function () {
        const randomNumber = Math.floor(Math.random() * phrases.length);
        document.getElementById('content').innerText = phrases[randomNumber].phrase;
        counter++;
        if (counter > 20) {
            window.clearInterval(setAnimation);
            document.getElementById('content').innerText = phrases[0].phrase;
            getRating();
            document.getElementById('category').innerText = "Category: " + phrases[0].category;
        }
    }
    var setAnimation = window.setInterval(animation, 40);
}

function getRating() {
    if (phrases[0].votes.length == 0) {
        document.getElementById('upvote').style.visibility = 'visible';
        document.getElementById('downvote').style.visibility = 'visible';
    } else if (phrases[0].votes[0].status == 1) {
        document.getElementById('upvote').style.visibility = 'visible';
        document.getElementById('downvote').style.visibility = 'hidden';
    } else {
        document.getElementById('upvote').style.visibility = 'hidden';
        document.getElementById('downvote').style.visibility = 'visible';
    }
    document.getElementById('rating').innerText = phrases[0].rating;
}

function vote(param) {
    if (phrases[0].votes.length != 0) {
        param = '/unvote';
        (phrases[0].votes[0].status == 1) ? phrases[0].rating-- : phrases[0].rating++;
        phrases[0].votes = [];
    } else if (param.includes('upvote')) {
        phrases[0].rating++;
        let vote = {
            status: 1
        }
        phrases[0].votes.push(vote);
    } else {
        phrases[0].rating--;
        let vote = {
            status: -1
        }
        phrases[0].votes.push(vote);
    }
    fetch('/strategies/' + phrases[0]._id + param, {
        method: "POST"
    }).then(res => {
        console.log(res.text());
    });
    getRating();
}
window.onload = loadData;