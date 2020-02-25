

Vue.component('dtt-spalte', {
    template: `<div class='list-group-item w-100 p-0'>
    <div class='text-center m-3'>{{schoof.zeile}}</div>
    <div class='list-group list-group-flush border'>
        <dtt-task v-bind:gans='gans' v-for='gans in schoof.inhalt' class='list-group-item'></dtt-task>
        
    </div></div>`,
    props: ['schoof']
});

Vue.component('dtt-task', {
    template: `
    <div>{{gans}}</div>
    `,
    props: ['gans']
})

var module = new Vue({
    el: '#app',
    data: {
        wasser: [],
    },
    methods: {

    },
    mounted() {
        
    }
});

const http = new XMLHttpRequest();
http.open("GET", "tasks.json");
http.onload = function () {
    module.wasser = JSON.parse(http.responseText)
};
http.send();