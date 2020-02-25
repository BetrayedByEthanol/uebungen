Vue.component('Task',{
    template: `
    <div class="card" style="max-width: 400px;">
    <div class="card-header">
        <a href="#" class="btn btn-success">Projekt</a> <a href="#" class="btn btn-info">Javascript</a> <a
            href="#" class="btn btn-primary">Vue</a> 
            <a href="#" class="btn btn-danger">Übernehmen</a>
    </div>
    <div class="card-body">
        <h5 class="card-title">TaskHeader</h5>
        <p class="card-text">(Optional)Lerne Vue!</p>
        <p class="card-text">Schreibe etwas Quelltext!</p>
        <p class="card-text">Behebe Programmierfehler</p>
        <a href="#" class="btn btn-primary"><=</a>
        <a href="#" class="btn btn-primary">=></a>
    </div>
</div>`,
    
})