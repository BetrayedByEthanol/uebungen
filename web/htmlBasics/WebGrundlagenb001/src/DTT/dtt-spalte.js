Vue.component('dtt-spalte', {
    template: `<div class='list-group-item w-100 p-0'>
    <div class='text-center m-3'>{{headers}}</div>
    <div class='list-group list-group-flush border'>
        <dtt-task v-bind:task="task" v-for="task in tasks" class='list-group-item'></dtt-task>
    </div></div>`,
    props: ['tasks','headers'],
});
