Vue.component('Spalten', {
    template: `<div class='list-group-item w-100 p-0'>
    <div class='text-center m-3'>fillertitle</div>
    <div class='list-group list-group-flush border'>
        <div class='list-group-item'>...filler1...</div>
        <div class='list-group-item'>...filler2...</div>
        <div class='list-group-item'>...filler3...</div>
        <div class='list-group-item'>...filler4...</div>
    </div></div>`,
    props: ['tec']
});

var module = new Vue({
    el: '#ape',
    data: {
        test: [1,2,3,4,5],
    },
    methods: {

    },
    mounted() {

    }
});