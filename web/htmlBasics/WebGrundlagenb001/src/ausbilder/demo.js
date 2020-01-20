
const minHeight = 20;
const maxheight = 100;

var animationCount = 20;

const divElements = ['div1', 'div2', 'div3'];

divElements.forEach(elementID =>{
    const element = document.getElementById(elementID);
    element.style.height = minHeight + 'px';
    element.setAttribute('bbw-closed', true);
});

var toggleMenu = function (divID) {

    const aElement = document.getElementById(divID);

    divElements.forEach(elementID =>{
        const element = document.getElementById(elementID);
        const menuclosed = element.getAttribute('bbw-closed');

        if ( elementID == divID && menuclosed) {
            element.style.height =  animationCount + 'px'; 
        } else if( elementID == divID && !menuclosed){
            element.style.height = 100 - animationCount + 'px';
        }
      
       // element.style.height = elementID == divID ? animationCount + 'px' :  + '0px';
        var wert = parseInt(element.getAttribute('animationCount'));
        console.log(1 + wert);
    });

    if(animationCount < 100) {
        window.setTimeout(toggleMenu,5, divID);
        animationCount++;
    } else {
        animationCount = 20;
        aElement.setAttribute('bbw-closed', false);
    }
}