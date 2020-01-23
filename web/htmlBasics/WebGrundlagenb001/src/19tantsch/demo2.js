var janein = {
    menu1: true,
    menu2: true,
    menu3: true
}
var platzhalter1 = document.getElementById("nreinsm").style;
var platzhalter2 = document.getElementById("nrzweim").style;
var platzhalter3 = document.getElementById("nrdreim").style;
var pixel = 0;
var platzhalter;



function expand(platzhalter1,platzhalter2,platzhalter3){
        
        platzhalter1.height = "0px";
        janein.menu1 = false;
        platzhalter2.height = "0px";
        platzhalter3.height = '0px';
    
}
/*function fill(welches){
    console.log("filler");
}*/

/*function expand(welches){
    fill(welches);
    pixel = platzhalter;
    expand2(welches);   
}

function expand2(welches){
    if(pixel < 72){
       
        platzhalter = pixel;
    }
    else if(pixel == 72){
        platzhalter = pixel;
    }
}*/