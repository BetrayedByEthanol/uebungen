Vue.component('dtt-spalte', {
    template: `<div class='list-group-item w-100 p-0'>
    <div class='text-center m-3'>{{schoof.zeile}}</div>
    <div class='list-group list-group-flush border'>
        <dtt-task v-bind:gans='gans' v-for='gans in schoof.inhalt' class='list-group-item'></dtt-task>
        
    </div></div>`,
    props: ['schoof']
});


Vue.component('dtt-task',{
    template: `
    <div class="card" style="max-width: 400px;">
    <div class="card-header">
        <a href="#" class="btn btn-success btn-sm">P</a> <a href="#" class="btn btn-info btn-sm">JS</a> <a
            href="#" class="btn btn-primary btn-sm">Vue</a> 
            <a href="#" class="btn btn-danger btn-sm">OK</a>
    </div>
    <div class="card-body">
        <h5 class="card-title">TaskHeader</h5>
        <p class="card-text">(Optional)Lerne Vue!</p>
        <p class="card-text">Schreibe etwas Quelltext!</p>
        <p class="card-text">Behebe Programmierfehler</p>
        <a href="#" class="btn btn-primary btn-sm">&#8656;</a>
        <a href="#" class="btn btn-primary btn-sm"> &#8658;</a>
    </div>
</div>`,
props: ['gans']
    
})



/*Vue.component('dtt-task', {
    template: `
    <div>{{gans}}</div>
    `,
    props: ['gans']
})*/

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