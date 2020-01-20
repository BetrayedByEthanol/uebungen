const Elements = ["Div1", "Div2", "Div3", "Div4"];

var animationKeyFrame = 0;
const minHeight = 15;
const maxHeight = 150;

Elements.forEach(Ids => {
        const elementId = document.getElementById(Ids);
        elementId.style.height = minHeight + 'px';
        elementId.setAttribute('DivFolded', true);
    });

function toggleVisibility(divId) {
    const openElement = document.getElementById(divId);

    Elements.forEach(Ids => {
        const divElement = document.getElementById(Ids);
        const closedElement = divElement.getAttribute('DivFolded');

        if (Ids == divID && closedElement) {
            divElement.style.height = animationKeyFrame + "px";
        } else if(Ids == divId && !closedElement) {
            divElement.style.height = animationKeyFrame + "px";
        }

     var blah = parseInt(divElement.getAttribute('animationKeyFrame'));
     console.log(1 + blah);
    });

    if(animationKeyFrame < 100) {
        window.setTimeout(toggleVisibility, 15, divId);
        animationKeyFrame++;
    } else {
        animationKeyFrame = 15;
        openElement.setAttribute('DivFolded', false);
    }
}