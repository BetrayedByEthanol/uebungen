Vue.component('card', {
    props: ['card'],
    template: `
    <div class="card container">
        <div class="item-refresh">
            <img
                class="refreshIcon"
                src="img/refresh.png"
                alt="refresh"
                v-on:click="module.loadData()"
            />
        </div>
        <div class="item-content font">
            <div id="content">{{module.curr_phrase}}</div>
        </div>
        <div class="item-category">
            <div id="category">{{curr_category}}</div>
        </div>
        <div class="item-rating">
            <div id="rating"></div>
        </div>
        <div class="item-timer">
            <img
                class="timerIcon"
                id="autoRefresh"
                src="img/timeroff.png"
                alt="autoRefresh"
                v-on:click="module.toggler()"
            />
        </div>
        <div class="halved">
            <div class="item-upvote">
                <img
                    id="upvote"
                    class="arrows"
                    src="img/arr_up.png"
                    alt="upvote"
                    v-on:click="module.vote('/upvote')"
                />
            </div>
            <div class="item-downvote">
                <img
                    id="downvote"
                    class="arrows"
                    src="img/arr_down.png"
                    alt="downvote"
                    v-on:click="module.vote('/downvote')"
                />
            </div>
        </div>
    </div>`
})



var module = new Vue({
    el: '#app',
    data: {
        curr_phrase: "",
        curr_category: "",
        phrases: [],
        autoRefresh: false,
        currentPhraseID: []
    },
    methods: {
        toggler: function() {
            if (autoRefresh == false) {
                autoRefresh = window.setInterval(loadData, 10000);
                document.getElementById('autoRefresh').src = 'img/timeron.png';
            } else {
                document.getElementById('autoRefresh').src = 'img/timeroff.png';
                window.clearInterval(autoRefresh);
                autoRefresh = false;
            }
        },
        
        loadData: function() {
            fetch('/strategySample/', { method: "GET" })
                .then(res => res.json())
                .then(data => {
                    phrases = data;
                });
            var counter = 0;
            this.animation(phrases);
            var setAnimation = window.setInterval(animation, 40);
        },
        
        animation: function(phrases) {
            const randomNumber = Math.floor(Math.random() * this.phrases.length);
            this.curr_phrase = phrases[randomNumber].phrase;
            counter++;
            if (counter > 20) {
                window.clearInterval(setAnimation);
                currentPhraseID = 0;
                this.curr_phrase = phrases[0].phrase;
                this.getRating();
                this.curr_category = "Category: " + phrases[0].category;
            }
        },

        getRating: function() {
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
        },
        
        vote: function(param) {
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
    },
    mounted() {
        
    }
})

window.onload = module.loadData;