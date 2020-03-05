Vue.component('dtt-task', {
    template: `
    <div class="card shadow p-3 mb-5 bg-white rounded" style="max-width: 400px;">
    <div class="card-header shadow-sm p-3 mb-2 bg-white rounded">
           
          <a href="#" class="btn btn-danger btn-sm align-self-start float-right">DO</a>Wird von <br>xxx<br> bearbeitet.
    </div>
    <div class="card-body">
    <h5 class="card-title" v-bind:task='task'>{{ task.name }}</h5>
        <p class="card-text font-weight-light" v-bind:task='task'>Kategorie: {{ task.category }}</p>
        <hr class="my-2">
        <p class="card-text font-weight-bolder">Inhalt:</p>
        <dtt-description v-bind:description='point' v-for='point in task.description'></dtt-description>
        <!--<p class="card-text" v-bind:task='task'>??: {{task.difficulty}}</p>-->
        <hr class="my-2">
        <a href="#" class="btn btn-primary btn-sm ">&#8656;</a>
        <a href="#" class="btn btn-primary btn-sm float-right"> &#8658;</a>
    </div>
</div>`,
    props: ['task']
});

