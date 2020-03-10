
Vue.component('card', {
    template: `
    <div class="card container">
        <div class="item-refresh">
            <img
                class="refreshIcon"
                src="img/refresh.png"
                alt="refresh"
                @click="module.loadData()"
            />
        </div>
        <div class="item-content font">
            <div id="content">{{ c_phrase }}</div>
        </div>
        <div class="item-category">
            <div id="category">{{ c_category }}</div>
        </div>
        <div class="item-rating">
            <div id="rating">{{ c_rating }}</div>
        </div>
        <div class="item-timer">
            <img
                class="timerIcon"
                id="autoRefresh"
                src="img/timeroff.png"
                alt="autoRefresh"
                @click="module.toggler()"
            />
        </div>
        <div class="halved">
            <div class="item-upvote">
                <img
                    id="upvote"
                    class="arrows"
                    src="img/arr_up.png"
                    alt="upvote"
                    @click="module.vote('/upvote')"
                />
            </div>
            <div class="item-downvote">
                <img
                    id="downvote"
                    class="arrows"
                    src="img/arr_down.png"
                    alt="downvote"
                    @click="module.vote('/downvote')"
                />
            </div>
        </div>
    </div>`,
    props: ['c_phrase', 'c_category', 'c_rating', 'autoReImg']
})

var module = new Vue({
    el: '#app',
    data: {
        curr_phrase: "",
        curr_category: "",
        curr_rating: null,
        phrases: [],
        autoRefresh: false,
        autoRefresh_img: 'img/timeroff.png',
        currentPhraseID: 0,
        setAnimation: 0,
        counter: 0
    },
    mounted() {
        this.loadData()
        //this.autoRefresh_img = require('img/timeroff.png') //require is not defined
    },

    methods: {
        set_img(img_path) {
            require(img_path)
        },
        toggler() {
            if (this.autoRefresh == false) {
                this.autoRefresh = window.setInterval(this.loadData, 10000)
                this.autoRefresh_img = 'img/timeron.png'
            } else {
                this.autoRefresh_img = 'img/timeroff.png'
                window.clearInterval(this.autoRefresh)
                this.autoRefresh = false
            }
        },
        loadData() {
            axios
                .get('/strategySample/')
                .then(res => {
                    this.phrases = res.data
                    this.counter = 0
                    this.setAnimation = window.setInterval(this.animation, 40)
                });
        },
        animation() {
            var randomNumber = Math.floor(Math.random() * this.phrases.length);
            this.curr_phrase = this.phrases[randomNumber].phrase;
            this.counter++
            if (this.counter > 20) {
                window.clearInterval(this.setAnimation)
                randomNumber = this.phrases.findIndex(p => { return p.display == true; })
                this.curr_phrase = this.phrases[randomNumber].phrase;
                this.curr_category = "Category: " + this.phrases[randomNumber].category
                this.currentPhraseID = randomNumber
                this.getRating()
            }
        },
        getRating() {
            if (this.phrases[this.currentPhraseID].votes.length == 0) {
                document.getElementById('upvote').style.visibility = 'visible'
                document.getElementById('downvote').style.visibility = 'visible'
            } else if (this.phrases[this.currentPhraseID].votes[0].status == 1) {
                document.getElementById('upvote').style.visibility = 'visible'
                document.getElementById('downvote').style.visibility = 'hidden'
            } else {
                document.getElementById('upvote').style.visibility = 'hidden'
                document.getElementById('downvote').style.visibility = 'visible'
            }
            this.curr_rating = this.phrases[this.currentPhraseID].rating
        },
        vote(param) {
            console.log(this.phrases[this.currentPhraseID].rating)
            if (this.phrases[this.currentPhraseID].votes.length != 0) {
                param = '/unvote'
                this.phrases[this.currentPhraseID].votes[0].status == 1 ? this.phrases[this.currentPhraseID].rating-- : this.phrases[this.currentPhraseID].rating++
                this.phrases[this.currentPhraseID].votes = []
            } else if (param.includes('upvote')) {
                this.phrases[this.currentPhraseID].rating++
                let vote = {
                    status: 1
                }
                this.phrases[this.currentPhraseID].votes.push(vote)
            } else {
                this.phrases[this.currentPhraseID].rating--
                let vote = {
                    status: -1
                }
                this.phrases[this.currentPhraseID].votes.push(vote)
            }
            axios
                .post('/strategies/' + this.phrases[this.currentPhraseID]._id + param)
            // .then(res => (console.log(res.text()))
            this.getRating()
        }
    }
})
