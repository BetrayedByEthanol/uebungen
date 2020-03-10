
var quotes = null;



var wennGeladen = function () {
    quotes = JSON.parse(http.responseText);

    // const zitatElement = document.getElementById('zitat');
    // const randomIndex = Math.floor(Math.random() * quotes.length);
    // zitatElement.innerText = quotes[randomIndex].quote;

    // const gruppe = ["ausbilder", "19adam", "19behm", "19nieke", "19peters", "19poeppmann", "19rose", "19seifert", "19soler", "19tantsch", "19zech"];

    // gruppe.forEach(teilnehmer => {

    //     const block = document.getElementById('applepie');
    //     const newBlock = block.cloneNode(true);
    //     newBlock.id = teilnehmer + 'nameID';
        
    //     newBlock.getElementsByTagName('h2')[0].innerText = teilnehmer;
    //     newBlock.getElementsByTagName('image')[0].setAttribute('href', 'img/' + teilnehmer + 'profile.png');
    //     newBlock.getElementsByTagName('a')[0].setAttribute('href', teilnehmer + 'profil.html');
       
    //     const quoteID = teilnehmer + 'quote';
    //     const quote = quotes.find(quote => quote.id == quoteID);
     
    //     if (quote) {
    //         newBlock.getElementsByTagName('span')[0].innerText = quote.quote;
    //         newBlock.getElementsByTagName('span')[1].innerText = quote.author.name;
    //     };
    //     const row = document.getElementById('row');
    //     row.appendChild(newBlock);
    //     newBlock.hidden = false;

    // });
}


// var loaadData = function () {
//    module.quotes = JSON.parse(http.responseText);
    
// };
// const http = new XMLHttpRequest();
// http.open("GET", "data/quotes.json");
// http.onload = loaadData;
// http.send()



var module = new Vue({
    el: '#app',
    data: {
        quotes: [],
        gruppe: ["ausbilder", "19adam", "19behm", "19nieke", "19peters", "19poeppmann", "19rose", "19seifert", "19soler", "19tantsch", "19zech"],
        mainquote: ''
    },
    methods: {
        getprofile: function (filter) {
            var fish = this.quotes.find(quote => {
                if(quote.id == filter + 'quote') {return true} else {return false}
            });
            if (fish) {
                return fish;
            } return 0;
        }
    },
    mounted: function () {
        const http = new XMLHttpRequest();
        http.open("GET", "data/quotes.json");
        http.onload = function () {
            module.quotes = JSON.parse(http.responseText);
            const randomIndex = Math.floor(Math.random() * module.quotes.length);
            module.mainquote = module.quotes[randomIndex].quote
        };
        http.send();
    }
});

Vue.component('profil', {
    template: `
    <div class="col-4">
        <svg
            class="bd-placeholder-img rounded-circle"
            width="140"
            height="140"
            xmlns="http://www.w3.org/2000/svg"
            preserveAspectRatio="xMidYMid slice"
            focusable="false"
            role="img"
            aria-label="Placeholder: 140x140"
            v-html="link"
        >
            <title>powered by Vue</title>
            <rect width="100%" height="100%" fill="#777" />
            <a href="profil.html">
                <image
                    href="img/profile.png"
                    x="0"
                    y="0"
                    height="100%"
                    width="100%"
                />
            </a>
        </svg>
        <h2>{{teilnehmer}}</h2>
        <span>{{profile.quote}}</span>
        <span class="blockquote-footer text-right">
            {{profile.author.name}}
        </span>
    </div>
    `,
    props: ['teilnehmer'],
    data: function () {
        return {
            profile: {},
            link:`
            <title>powered by Vue</title>
            <rect width="100%" height="100%" fill="#777" />
            <a href="`+this.teilnehmer+`profil.html">
                <image
                    href="img/`+this.teilnehmer+`profile.png"
                    x="0"
                    y="0"
                    height="100%"
                    width="100%"
                />
            </a>`
        }
    },
    mounted: function () {
        this.profile = this.$root.getprofile(this.teilnehmer);
    }
});

// const http = new XMLHttpRequest();
//         http.open("GET", "data/quotes.json");
//         http.onload = loaadData();
//         http.send();