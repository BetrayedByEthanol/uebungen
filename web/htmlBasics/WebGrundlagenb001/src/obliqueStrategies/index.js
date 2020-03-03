
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
            <div id="content">{{ curr_phrase }}</div>
        </div>
        <div class="item-category">
            <div id="category">{{ curr_category }}</div>
        </div>
        <div class="item-rating">
            <div id="rating">{{ curr_rating }}</div>
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
    props: ['curr_phrase', 'curr_category', 'curr_rating']
})


var module = new Vue({
    el: '#app',
    data: {
        curr_phrase: "",
        curr_category: "",
        curr_rating: null,
        phrases: [],
        autoRefresh: false,
        currentPhraseID: 0,
        setAnimation: 0,
        counter: 0
    },
    mounted() {
        this.loadData()
    },

    methods: {
        toggler() {
            if (this.autoRefresh == false) {
                this.autoRefresh = window.setInterval(this.loadData, 10000)
                document.getElementById('autoRefresh').src = 'img/timeron.png'
            } else {
                document.getElementById('autoRefresh').src = 'img/timeroff.png'
                window.clearInterval(this.autoRefresh)
                this.autoRefresh = false
            }
        },
        loadData() {
            axios
                .get("obliqueStrats.json")
                .then(response => (this.phrases = response.data))
            this.counter = 0
            this.setAnimation = window.setInterval(this.animation, 40)
        },
        animation() {
            const randomNumber = Math.floor(Math.random() * this.phrases.length)
            this.curr_phrase = this.phrases[randomNumber].phrase
            this.curr_category = "Category: " + this.phrases[randomNumber].category
            this.counter++
            if (this.counter > 20) {
                window.clearInterval(this.setAnimation)
                this.currentPhraseID = randomNumber
                if (this.phrases[this.currentPhraseID].votes == undefined) this.phrases[this.currentPhraseID].votes = []
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
            if (this.phrases[this.currentPhraseID].votes.length != 0) {
                param = '/unvote'
                (this.phrases[this.currentPhraseID].votes[0].status == 1) ? this.phrases[this.currentPhraseID].rating-- : this.phrases[this.currentPhraseID].rating++
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
            fetch('/strategies/' + this.phrases[this.currentPhraseID]._id + param, {
                method: "POST"
            }).then(res => {
                console.log(res.text())
            })
            this.getRating()
        }
    }
})