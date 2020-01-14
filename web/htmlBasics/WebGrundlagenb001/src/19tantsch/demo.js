let wer;
let welche;
var offen = true;
var janein = {
    menu1: true,
    menu2: true,
    menu3: true
}
var i;

function verschwinden(wer, welche) {
    if (wer == nreins && janein.menu1 == true) {
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
    if (wer == nreins && janein.menu1 == false) {


        
        document.getElementById("nreinsm").style.height = "72px";
        janein.menu1 = true;
        return;
    } else if (wer == nrzwei && janein.menu2 == false) {
        document.getElementById("nrzweim").style.height = "72px";
        janein.menu2 = true;
        return;

    } else if (wer == nrdrei && janein.menu3 == false) {
        document.getElementById("nrdreim").style.height = "72px";
        janein.menu3 = true;
        return;
    }

}


/* else if (wer === nrzwei && offen == true) {
    setTimeout(function(){ document.getElementById(welche).style.height = "65px"; }, 25);            
    setTimeout(function(){ document.getElementById(welche).style.height = "55px"; }, 50);
    setTimeout(function(){ document.getElementById(welche).style.height = "45px"; }, 75);
    setTimeout(function(){ document.getElementById(welche).style.height = "35px"; }, 100);
    setTimeout(function(){ document.getElementById(welche).style.height = "25px"; }, 125);
    setTimeout(function(){ document.getElementById(welche).style.height = "15px"; }, 150);
    setTimeout(function(){ document.getElementById(welche).style.height = "5px"; }, 175);
    setTimeout(function(){ document.getElementById(welche).style.height = "0px"; }, 200);
    offen = false;
    return;

} else if (wer === nrdrei && offen == true) {
    for(i = 25; i <= 0; i + 25){
    setTimeout(function(){ document.getElementById("nrdreim").style.height = i + "0px"; }, 25);
    }
    offen = false;
    return;
}*/
/* if(wer == nreins){
    janein.menu1 = false;
    return;
}
else if(wer == nrzwei){
    janein.menu2 = false;
    return;}
else if(wer == nrdrei){
    janein.menu3 = false;
    return;}
}*/