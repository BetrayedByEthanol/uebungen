Vue.component('ocardid', {
    template: `
    <span class="container-fluid align-items-center">
    <button @click="multiView()" type="button" class="btn btn-dark btn-block align-left">Back</button>
  <div class="jumbotron bg-primary">
  <h5 class="display-4 text-center">{{stratprop.phrase}}</h5>
  <p class="text-right">{{stratprop.category.join(', ')}}</p>
  </div></span>`,

    props: ['stratprop', 'conditionaltrigger'],


    methods: {
        multiView: function () {
            this.$parent.stratprop = [];
            this.$parent.conditionaltrigger = false;
        }
    }
});

Vue.component('o-card', {

    template: `
    <div class="card" v-bind:class="{ 'bg-info': strategy.category.includes('Growth'), 'bg-primary': strategy.category.includes('New Perspective') }" v-on:click="singleView(strategy)">
    <h5 class="card-title">{{strategy.phrase}}</h5>
    <p class="align-text-right">{{strategy.category.join(', ')}}</p>
    
    </div>`,
    props: ['strategy', 'conditionaltrigger'],


    methods: {
        singleView: function (strat) {
            this.$parent.stratprop = strat;
            this.$parent.conditionaltrigger = true;
        }
    }
});

var blablabla;

var app = new Vue({

    el: '#app',
    data: {
        strategies: [],
        stratprop: [],
        conditionaltrigger: false,
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
            if (choose != 'Alle Kategorien') {
                var result = this.strategies.filter(function (testsubject) {
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