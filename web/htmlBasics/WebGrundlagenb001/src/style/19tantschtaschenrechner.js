function eins(){
    document.getElementById('schirm').innerHTML += 1;
}

function zwei(){
    document.getElementById('schirm').innerHTML += 2;
}

function drei(){
    document.getElementById('schirm').innerHTML += 3;
}

function vier(){
    document.getElementById('schirm').innerHTML += 4;
}

function fuenf(){
    document.getElementById('schirm').innerHTML += 5;
}

function sechs(){
    document.getElementById('schirm').innerHTML += 6;
}

function sieben(){
    document.getElementById('schirm').innerHTML += 7;
}

function acht(){
    document.getElementById('schirm').innerHTML += 8;
}

function neun(){
    document.getElementById('schirm').innerHTML += 9;
}

function zero(){
    document.getElementById('schirm').innerHTML += 0;
}


var links;
var rechts;
var ident;
var result;

function addiere(){
    this.links = document.getElementById('schirm').innerHTML;
    document.getElementById('schirm').innerHTML = '';
    this.ident = 1;
}
function subtrahiere(){
    this.links = document.getElementById('schirm').innerHTML;
    document.getElementById('schirm').innerHTML = '';
    this.ident = 2;
}
function multipliziere(){
    this.links = document.getElementById('schirm').innerHTML;
    document.getElementById('schirm').innerHTML = '';
    this.ident = 3;
}
function dividiere(){
    this.links = document.getElementById('schirm').innerHTML;
    document.getElementById('schirm').innerHTML = '';
    this.ident = 4;
}


function loese(){

    switch(ident){
        case 1:
        this.rechts = document.getElementById('schirm').innerHTML;
        this.ergebnis = parseInt(this.links) + parseInt(this.rechts);
        document.getElementById('schirm').innerHTML = this.ergebnis;
        this.ident = 0;break;
        case 2:
        this.rechts = document.getElementById('schirm').innerHTML;
        this.ergebnis = this.links - this.rechts;
        document.getElementById('schirm').innerHTML = this.ergebnis;
        this.ident = 0;break;
        case 3:
        this.rechts = document.getElementById('schirm').innerHTML;
        this.ergebnis = this.links * this.rechts;
        document.getElementById('schirm').innerHTML = this.ergebnis;
        this.ident = 0;break;
        case 4:
        this.rechts = document.getElementById('schirm').innerHTML;
        this.ergebnis = this.links / this.rechts;
        document.getElementById('schirm').innerHTML = this.ergebnis;
        this.ident = 0;break;
        default:console.log('fehler400');
    }
}

function leere(){    
    document.getElementById('schirm').innerHTML = '';
    this.ergebnis = '';
    this.links = '';
    this.rechts = '';
}
