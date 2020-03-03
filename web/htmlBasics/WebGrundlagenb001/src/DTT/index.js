
FIXME:// use Vue.component to filter the JSON Data, not JSON itself!
Vue.config.devtools = true;
Vue.component('dtt-spalte', {
    template: `<div class='list-group-item w-100 p-0'>
    <div class='text-center m-3'>{{kategorie.zeile}}</div>
    <div class='list-group list-group-flush border'>
        <dtt-task v-bind:taskElement='taskElement' v-for='taskElement in kategorie.inhalt' class='list-group-item'></dtt-task> 
    </div></div>`,
    props: ['kategorie'],
});


Vue.component('dtt-task', {
    template: `
    <div class="card shadow p-3 mb-5 bg-white rounded" style="max-width: 400px;">
    <div class="card-header shadow-sm p-3 mb-2 bg-white rounded">
           
          <a href="#" class="btn btn-danger btn-sm align-self-start float-right">DO</a>Wird von <br>xxx<br> bearbeitet.
    </div>
    <div class="card-body">
    <h5 class="card-title">{{ taskElement.name }}</h5>
        <p class="card-text font-weight-light" v-bind:taskElement='taskElement'>Kategorie: {{ taskElement.category }}</p>
        <hr class="my-2">
        <p class="card-text font-weight-bolder">Inhalt:</p>
        <dtt-description v-bind:description='point' v-for='point in taskElement.description'></dtt-description>
        <!--<p class="card-text" v-bind:taskElement='taskElement'>??: {{taskElement.difficulty}}</p>-->
        <hr class="my-2">
        <a href="#" class="btn btn-primary btn-sm ">&#8656;</a>
        <a href="#" class="btn btn-primary btn-sm float-right"> &#8658;</a>
    </div>
</div>`,
    props: ['taskElement']

});

Vue.component('dtt-description', {
    template: `
    <p>&#187; {{description}}</p>
    `,
    props: ['description']
})

var module = new Vue({
    el: '#app',
    data: {
        taskCollection: [],
    },
    methods: {

    },
    mounted() {
    const http = new XMLHttpRequest();
    http.open("GET", "tasks.json");
    http.onload = function () {
    module.wasser = JSON.parse(http.responseText)
    };
    http.send();

    }
});

const http = new XMLHttpRequest();
http.open("GET", "tasks.json");
http.onload = function () {
    module.taskCollection = JSON.parse(http.responseText)
};
http.send();
