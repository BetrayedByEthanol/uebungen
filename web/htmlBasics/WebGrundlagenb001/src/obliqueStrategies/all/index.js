
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

var filterlist = function () {
    while(document.getElementById('Kategorieliste').hasChildNodes == true) {
        document.getElementById('Kategorieliste').firstChild.remove();
    }
    document.getElementById('Kategorieliste').hidden = null;
    const liste = ['Alle Kategorien','Growth','New Perspective','Programming','Philosophical','Self-Care','Self-Confidence','Technology'];
    liste.sort();
    liste.forEach(eintrag => {
        if(document.getElementById('Kategoriefeld').innerText != eintrag) {
            var newdiv = document.createElement('div');
            document.getElementById('Kategorieliste').append(newdiv);
            newdiv.id = 'Kategorie' + liste.indexOf(eintrag);
            newdiv.innerText = eintrag;
            newdiv.setAttribute('onclick','filter("' + eintrag + '")');
        }
    });
};

var filter = function (choose) {
    document.getElementById('Kategorieliste').hidden = true;
    const carddeck = document.querySelectorAll('[classname="card"]');
    carddeck.forEach(card => {
        card.hidden = true;
    });
    carddeck.forEach(card => {
        if(card.getElementsByTagName('p').innerText.includes(choose)) {
            card.hidden = false;
        }
    })
    document.getElementById('Kategoriefeld').innerText = choose
};