var patharray = window.location.pathname.split('/');
var pathname = patharray[patharray.length - 1].substr(0,patharray[patharray.length-1].indexOf('.'));
Vue.component('ocardid', {
  template: `
<div class="jumbotron bg-primary" >
<h5 class="display-4 text-center">{{strategy.phrase}}</h5>
<p class="text-right">{{strategy.category.join(', ')}}</p>
</div>`,

  props: ['strategy']
});


var app = new Vue({
  el: '#app',
  data: {
    strategy: []
  },

  mounted() {
    axios
      .get('/strategies/' + pathname)
      .then(response => (this.strategy = response.data));
  }
});