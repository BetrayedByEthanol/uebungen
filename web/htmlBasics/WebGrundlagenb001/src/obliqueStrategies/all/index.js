
Vue.component('o-card', {

    template: `
    <div class="card" v-bind:class="{ 'bg-info': strategy.category.includes('Growth'), 'bg-primary': strategy.category.includes('New Perspective') }">
    <h5 class="card-title">{{strategy.phrase}}</h5>
    <p class="align-text-right">{{strategy.category.join(', ')}}</p>
    
    </div>`,
    props: ['strategy']
});
var blablabla;

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
        },
        filtriere: function (choose) {
            document.getElementById('Kategorieliste').hidden = true;
            document.getElementById('Kategoriefeld').innerText = choose;
            this.reset();
            if(choose != 'Alle Kategorien') {
                var result = this.strategies.filter(function(testsubject) {
                   return testsubject.category.includes(choose);
                });
                this.strategies = result;
            }
        },
        reset: function () {
            this.strategies = blablabla;
        }
    },
    mounted() {
        axios.get('/strategies').then(response => (this.strategies = response.data));
        axios.get('/strategies').then(response => (blablabla = response.data))
    }
});

var filterlist = function () {
    document.getElementById('Kategorieliste').hidden = !(document.getElementById('Kategorieliste').hidden);
};
