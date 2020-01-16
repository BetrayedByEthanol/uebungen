var t = 0;
var height = 1;

function open_cont(num) {
    var conta = document.getElementsByClassName("cont")[num];
    if (conta.style.display == "none") {conta.style.display = "block"
        conta.style.height = height + "px";
        const inter = setInterval(function() {
            height += 1;
            conta.style.height = height + "px";
            t += 1;
            console.log(t);
            if (t >= 100) {
                clearInterval(inter);
                t = 0;
                height = 1;
            }
        }, 10);
    }  
    else {conta.style.display = "none"}
}