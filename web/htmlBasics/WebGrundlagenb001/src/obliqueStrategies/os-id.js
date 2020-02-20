Vue.component('ocardid', {
    template: `
    <div class="jumbotron bg-primary" >
    <h5 class="display-4 text-center">{{strategy.phrase}}</h5>
    <p class="text-right">{{strategy.category.join(', ')}}</p>
    </div>`,

    props: ['strategy']
})
// TODO: replace ID with var
var app = new Vue({
        el: '#app',
        data: {
            strategy: []
        },
        mounted() {
            axios
                .get('/strategies/5e2ffe4873c7467d98267cc1')
                .then(response => (this.strategy = response.data));
        }
    })
