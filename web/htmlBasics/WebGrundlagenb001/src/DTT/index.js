FIXME:// use Vue.component to filter the JSON Data, not JSON itself!

var module = new Vue({
    el: '#app',
    data: {
        tasks: [],
        headers:['Backlog','toDo','in Progress','Testing','Finished'],
    },
    methods: {
        
    },
    mounted() {
    const http = new XMLHttpRequest();
    http.open('GET', 'tasks.json');
    http.onload = function () {
    module.tasks = JSON.parse(http.responseText)
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
