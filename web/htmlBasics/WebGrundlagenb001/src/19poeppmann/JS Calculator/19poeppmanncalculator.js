
/*
function eingabe(zahl) {
    var ergebnistest
    ergebnistest = zahl;
    document.getElementById("anzeige").innerText = ergebnistest;
  }
  */
 var ident;
 var zahl;
 var zahl2;
 var ergebnis;


 function eins(){
    document.getElementById("eingabe").innerHTML += 1;
    this.zahl = 1;
}

function zwei(){
    document.getElementById("eingabe").innerHTML += 2;
    this.zahl = 2;
}

function drei(){
    document.getElementById("eingabe").innerHTML += 3;
    this.zahl = 3;
}

function vier(){
    document.getElementById("eingabe").innerHTML += 4;
    this.zahl = 4;
}

function fuenf(){
    document.getElementById("eingabe").innerHTML += 5;
    this.zahl = 5;
}

function sechs(){
    document.getElementById("eingabe").innerHTML += 6;
    this.zahl = 6;
}

function sieben(){
    document.getElementById("eingabe").innerHTML += 7;
    this.zahl = 7;
}

function acht(){
    document.getElementById("eingabe").innerHTML += 8;
    this.zahl = 8;
}

function neun(){
    document.getElementById("eingabe").innerHTML += 9;
    this.zahl = 9;
}

function zero(){
    document.getElementById("eingabe").innerHTML += 0;
    this.zahl = 0;
}

function leere(){    
    document.getElementById("eingabe").innerHTML = "";
    this.ergebnis = "";

}

function addiere(){
    document.getElementById("eingabe").innerText += '+' ;
    this.ident = 1;
}
function subtrahiere(){

    document.getElementById("eingabe").innerText += '-' ;
    this.ident = 2;
}
function multipliziere(){

    document.getElementById("eingabe").innerText += '*'  ;
    this.ident = 3;
}
function dividiere(){

    document.getElementById("eingabe").innerText += '/' ;
    this.ident = 4;
}

function loese(){

    switch(ident){
        case 1:
            this.ergebnis = this.zahl + this.zahl;
            document.getElementById("eingabe").innerText += '=' + ergebnis;
            break;
        case 2:
            this.ergebnis = this.zahl - this.zahl;
            document.getElementById("eingabe").innerText += '=' + ergebnis;
            break;
        case 3:
            this.ergebnis = this.zahl * this.zahl;
            document.getElementById("eingabe").innerText += '=' + ergebnis;
            break;
        case 4:
            //this.ergebnis = this.zahl / this.zahl;
            this.ergebnis = parseInt(this.zahl)
            document.getElementById("eingabe").innerText += '=' + ergebnis;
            break;
    }
}