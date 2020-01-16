let wer;
let welche;
var offen = true;
var janein = {
    menu1: true,
    menu2: true,
    menu3: true
}
let x;
let y;

function verschwinden(wer, welche) {              
    if (wer == nreins && janein.menu1 == true) {        //die nächsten drei if Bedingungen kümmern sich um das ausfahren.
        setTimeout(function () {
            document.getElementById(welche).style.height = "65px";
        }, 25); //die setTimeout funktion wird direkt ausgeführt, weshalb man den Abständen die Intervallgröße in Millisekunden zuweist
        setTimeout(function () {
            document.getElementById(welche).style.height = "55px";
        }, 50);
        setTimeout(function () {
            document.getElementById(welche).style.height = "45px";
        }, 75);
        setTimeout(function () {
            document.getElementById(welche).style.height = "35px";
        }, 100);
        setTimeout(function () {
            document.getElementById(welche).style.height = "25px";
        }, 125);
        setTimeout(function () {
            document.getElementById(welche).style.height = "15px";
        }, 150);
        setTimeout(function () {
            document.getElementById(welche).style.height = "5px";
        }, 175);
        setTimeout(function () {
            document.getElementById(welche).style.height = "0px";
        }, 200);
        janein.menu1 = false;
        return; //dieser Wert ist wichtig damit die Funktion aufhört, wenn Sie ihr arbeit gemacht hat.
    } else if (wer == nrzwei && janein.menu2 == true) {
        setTimeout(function () {
            document.getElementById(welche).style.height = "65px";
        }, 25); //die setTimeout funktion wird direkt ausgeführt, weshalb man den Abständen die Intervallgröße in Millisekunden zuweist
        setTimeout(function () {
            document.getElementById(welche).style.height = "55px";
        }, 50);
        setTimeout(function () {
            document.getElementById(welche).style.height = "45px";
        }, 75);
        setTimeout(function () {
            document.getElementById(welche).style.height = "35px";
        }, 100);
        setTimeout(function () {
            document.getElementById(welche).style.height = "25px";
        }, 125);
        setTimeout(function () {
            document.getElementById(welche).style.height = "15px";
        }, 150);
        setTimeout(function () {
            document.getElementById(welche).style.height = "5px";
        }, 175);
        setTimeout(function () {
            document.getElementById(welche).style.height = "0px";
        }, 200);
        janein.menu2 = false;
        return;
    } else if (wer == nrdrei && janein.menu3 == true) {
        setTimeout(function () {
            document.getElementById(welche).style.height = "65px";
        }, 25); //die setTimeout funktion wird direkt ausgeführt, weshalb man den Abständen die Intervallgröße in Millisekunden zuweist
        setTimeout(function () {
            document.getElementById(welche).style.height = "55px";
        }, 50);
        setTimeout(function () {
            document.getElementById(welche).style.height = "45px";
        }, 75);
        setTimeout(function () {
            document.getElementById(welche).style.height = "35px";
        }, 100);
        setTimeout(function () {
            document.getElementById(welche).style.height = "25px";
        }, 125);
        setTimeout(function () {
            document.getElementById(welche).style.height = "15px";
        }, 150);
        setTimeout(function () {
            document.getElementById(welche).style.height = "5px";
        }, 175);
        setTimeout(function () {
            document.getElementById(welche).style.height = "0px";
        }, 200);
        janein.menu3 = false;
        return;
    }                   
    if (wer == nreins && janein.menu1 == false) {           //ab hier sind die drei If-Bedingungen zum einklappen
        setTimeout(function () {
            document.getElementById(welche).style.height = "5px";
        }, 25);
        setTimeout(function () {
            document.getElementById(welche).style.height = "15px";
        }, 50);
        setTimeout(function () {
            document.getElementById(welche).style.height = "25px";
        }, 75);
        setTimeout(function () {
            document.getElementById(welche).style.height = "35px";
        }, 100);
        setTimeout(function () {
            document.getElementById(welche).style.height = "45px";
        }, 125);
        setTimeout(function () {
            document.getElementById(welche).style.height = "55px";
        }, 150);
        setTimeout(function () {
            document.getElementById(welche).style.height = "65px";
        }, 175);
        setTimeout(function () {
            document.getElementById(welche).style.height = "72px";
        }, 200);
        janein.menu1 = true;
        return;
    }
    else if (wer == nrzwei && janein.menu2 == false) {
        setTimeout(function () {
            document.getElementById(welche).style.height = "5px";
        }, 25);
        setTimeout(function () {
            document.getElementById(welche).style.height = "15px";
        }, 50);
        setTimeout(function () {
            document.getElementById(welche).style.height = "25px";
        }, 75);
        setTimeout(function () {
            document.getElementById(welche).style.height = "35px";
        }, 100);
        setTimeout(function () {
            document.getElementById(welche).style.height = "45px";
        }, 125);
        setTimeout(function () {
            document.getElementById(welche).style.height = "55px";
        }, 150);
        setTimeout(function () {
            document.getElementById(welche).style.height = "65px";
        }, 175);
        setTimeout(function () {
            document.getElementById(welche).style.height = "72px";
        }, 200);
        janein.menu2 = true;
        return;
    }
    else if (wer == nrdrei && janein.menu3 == false) {
        setTimeout(function () {
            document.getElementById(welche).style.height = "5px";
        }, 25);
        setTimeout(function () {
            document.getElementById(welche).style.height = "15px";
        }, 50);
        setTimeout(function () {
            document.getElementById(welche).style.height = "25px";
        }, 75);
        setTimeout(function () {
            document.getElementById(welche).style.height = "35px";
        }, 100);
        setTimeout(function () {
            document.getElementById(welche).style.height = "45px";
        }, 125);
        setTimeout(function () {
            document.getElementById(welche).style.height = "55px";
        }, 150);
        setTimeout(function () {
            document.getElementById(welche).style.height = "65px";
        }, 175);
        setTimeout(function () {
            document.getElementById(welche).style.height = "72px";
        }, 200);
        janein.menu3 = true;
        return;
    }
}
       
       
    