function getelement(event) {
    let clicked_div = event.target;

    Array.from(document.getElementsByClassName('div')).forEach(element => {
        if (element.style.height != '40px' && element != clicked_div) {
            console.log("setting size of", element.id, "to 40");

            function shrink(element) {
                var size = element.style.height;
                
                size = parseInt(size);
                var interval = setInterval(frame, 15);

                function frame() {
                    if (size == 40) {
                        clearInterval(interval);
                    } else {
                        size--;
                        element.style.height = size + 'px';
                        
                    }
                }
            }
            shrink(element);
        } else {
            function grow(element) {
                var size = element.style.height;
                
                size = parseInt(size);
                var interval = setInterval(frame, 15);

                function frame() {
                    if (size == 120) {
                        clearInterval(interval);
                    } else {
                        size++;
                        element.style.height = size + 'px';
                       
                    }
                }
            }
            grow(element);
        }
    });
    setTimeout(() => {
        if (clicked_div.style.height == 40) {
            console.log("Setting Size of", clicked_div.id, "to 120px");


        } else {}
    }, 300);
}

Array.from(document.getElementsByClassName('div')).forEach(element => {
    console.log('addEventListener on ', element);
    element.addEventListener('click', getelement);
});