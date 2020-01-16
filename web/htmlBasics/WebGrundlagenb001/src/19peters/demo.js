var height = 1;

function open_cont(num) {
    var conta = document.getElementsByClassName("cont")[num];
    if (conta.style.display == "none") {
        conta.style.display = "block";
        conta.firstElementChild.style.display = "none";
        const inter = setInterval(function() {
            height += 1;
            conta.style.height = height + "px";
            if (height >= 100) {
                clearInterval(inter);
                conta.firstElementChild.style.display = "block";
            }
        }, 10);
    }  
    else {
        conta.firstElementChild.style.display = "none";
        const onter = setInterval(function() {
            height += -1;
            conta.style.height = height + "px";
            if (height <= 1) {
                clearInterval(onter);
                conta.style.display = "none";
            }
        }, 10);
    }
}