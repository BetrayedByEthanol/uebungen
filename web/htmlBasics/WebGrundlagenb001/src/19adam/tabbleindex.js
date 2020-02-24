
Vue.component('tablehead', {

    template: `
    <div><thead>
    <th>Quote</th>
    <th>Author</th>
    <th>Age</th>
    <th>quoteid</th>
    </thead>
    </div>
    `

});

Vue.component('quoterow', {

    template: `
    <div><tr>
    <td>{{quote.quote}}</td>
    <td>{{quote.author.name}}</td>
    <td>{{quote.author.age}}</td>
    <td>{{quote.id}}</td>
    </tr></div>
    `,
    props: ['quote']

});

Vue.component('quotestable', {

    template: `
    <div>
        <b-table striped hover :quotesdata="quotesdata"></b-table>
    </div>
    `,
    props: ['quotesdata']

});

var app = new Vue({

    el:'#app',
    data: {

        quotesdata: []

    },
    methods: {

        sortby: function(n) {

            this.quotesdata.sort(function (a, b) {

                if(n==0){
                    if(a.quote > b.quote) return 1;
                    if(a.quote < b.quote) return -1;
                }else if(n==1) {
                    if(a.name > b.name) return 1;
                    if(a.name < b.name) return -1;
                }else if(n==2) {
                    if(a.age > b.age) return 1;
                    if(a.age < b.age) return -1;
                }

            })

            },
        searchinput: function() {

            var i, input, filterby, table, tablerows, rowel;

            input = document.getElementById('search').value;
            filterby = input.toLowerCase();
            table = document.getElementById('doctable');
            tablerows = table.rows;

            for(i = 1; i < (tablerows.length); i++){

                rowel = tablerows[i].innerText;
                console.log(rowel);

                if(rowel){

                    if(rowel.toLowerCase().indexOf(filterby) < 0){

                        tablerows[i].style.display = "none";

                    }

                }

            }

        }

    },
    mounted() {

        /*this.$axios.get('../data/quotes.json').then(response => (this.quotesdata = response.data)).then(gentable());*/
        axios.get('../data/quotes.json').then(response => (this.quotesdata = response.data));

    }

});