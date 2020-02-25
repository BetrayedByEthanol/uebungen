var toggleMe;

const app = new Vue({
    el: "#app",

    data: {
        loading: false, 
        phrases: null,
        error: null

    },
    created () {
        this.loadData()
    },
    watch: {
        '$route': '/strategy/'
    },

    methods: {
         toggler: function() {
            toggleMe = !toggleMe;
            if (toggleMe == true) {
                autoRefresh = window.setInterval(loadData, 10000);
                document.getElementById('autoRefresh').src = 'img/timeron.png';
            } else {
                document.getElementById('autoRefresh').src = 'img/timeroff.png';
                window.clearInterval(autoRefresh);
            }
        },
        loadData: function(){
            this.error = this.phrases = null
            this.loading  = true

            fetch('/strategy/', (err, phrases) => {
                this.loading = false
                if(err){
                    this.error = err.toString()
                }else {
                    this.phrases = phrases
                }
            })
        }
    }

})