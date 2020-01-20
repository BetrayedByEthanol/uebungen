var div1 = {
    box: document.getElementById('div1'),
    isMouseOn: false,
    isClicked: false,
    newHeight: 100,
    heightlock: 100,
    anima: 0
}
var div2 ={
    box: document.getElementById('div2'),
    isMouseOn: false,
    isClicked: false,
    newHeight: 100,
    heightlock: 100,
    anima: 0
}
var div3 ={
    box: document.getElementById('div3'),
    isMouseOn: false,
    isClicked: false,
    newHeight: 100,
    heightlock: 100,
    anima: 0
}
const alldiv = [div1, div2, div3];
var time;
function mouseOver(block) {
    block.isMouseOn = true;
    block.anima = 10 - block.anima;
    if(alldiv.every(test => {return test.isClicked == false})) {
        checkblock(block);
    }
}
function mouseOut(block) {
    block.isMouseOn = false;
    block.anima = 10 - block.anima;
    if(alldiv.every(test => {return test.isClicked == false})) {
        checkblock(block);
    }
}
function klick(block) {
    block.isClicked = !(block.isClicked);
    block.anima = 0;
    alldiv.forEach(divblock => checkblock(divblock));
}
function checkblock(block) {
    if(block.isMouseOn == true) {
        block.newHeight = 200;
        dewIt(block);
    } else {
        block.newHeight = 100;
        dewIt(block);
    }
}
function dewIt(block) {
    if(block.isClicked == true) {
        //FAST
        block.box.style.height = block.newHeight + 'px';
        block.heightlock = block.newHeight;
        if(block.newHeight == 100) {
            block.isClicked = false;
        }
    } else {
        //SLOW
        if(block.heightlock != block.newHeight) {
            console.log(block);
            time = window.setTimeout(swooshaa, 10, block);
        }
    }
}
function swooshaa(block) {
    if(block.anima > 0) {
        var summe = (block.anima - 1) * 10;
        switch(block.newHeight) {
            case 100:
                block.box.style.height = block.newHeight + summe + 'px';
                break;
            case 200:
                block.box.style.height = block.newHeight - summe + 'px';
        }
        block.anima--;
        time = window.setTimeout(swooshaa, 10, block);
    }
    block.heightlock = block.newHeight;
}