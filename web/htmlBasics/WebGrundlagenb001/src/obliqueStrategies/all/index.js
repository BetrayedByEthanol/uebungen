
Vue.component('o-card', {

    template: `
    <div class="card" >
    <h5 class="card-title">{{strategy.phrase}}</h5>
    <p class="align-text-right">{{strategy.category.join(', ')}}</p>
    
    </div>`,
    props: ['strategy']
});

var app = new Vue({

    el: '#app',
    data: {
        strategies: []
    },
    methods: {
        sortiere: function () {
            this.strategies.sort(function (a, b) {
                if (a.phrase > b.phrase) return 1;
                if (b.phrase > a.phrase) return -1;
            })
        }
    },
    mounted() {
        axios
            .get('/strategies')
            .then(response => (this.strategies = response.data));
    }
});