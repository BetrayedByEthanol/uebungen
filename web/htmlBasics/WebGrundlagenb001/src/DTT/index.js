Vue.component('Spalten', {
    template: `<div class='list-group-item w-100 p-0'>
    <div class='text-center m-3'>fillertitle</div>
    <div class='list-group list-group-flush border'>
        <Einzeltask v-bind:gans='gans' v-for='gans in schoof' class='list-group-item'></Einzeltask>
        
    </div></div>`,
    props: ['schoof']
});

Vue.component('Einzeltask', {
    template: `
    <div>{{gans}}</div>
    `,
    props: ['gans']
})

var module = new Vue({
    el: '#ape',
    data: {
        wasser: [[1,2,3,4,5],[1,2,3,4,5],[1,2,3,4,5],[1,2,3,4,5],[1,2,3,4,5]],
    },
    methods: {

    },
    mounted() {

    }
});