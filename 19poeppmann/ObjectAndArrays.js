var wert = "Ich bin ein String"; //initialisierung und deklaration einer Variablen

var mehrereWerte =[]; //initialisierung eines Arrays kann auch definiert werden

mehrereWerte[0] = "Erster Wert"; //erster Array mit einem String
mehrereWerte[1] = "Zweiter Wert"; //zweiter Wert mit einem String
mehrereWerte[2] = 453; //dritter Wert mit einer Zahl
mehrereWerte[3] = false; //vierter Wert mit einem Boolean

console.log(mehrereWerte[1]); //gebe Array 3 aus

var a = new Array(); //andere Initiliasierung eines Arrays

var b = Array();  //andere Initiliasierung eines Arrays

console.log(mehrereWerte.length); //Anzeige der Länge des Arrays

for (var i = 0; i < mehrereWerte.length; i++){  
    console.log ("Der 1. Wert (Index "+i+") des Arrays ist: " + mehrereWerte[i] ); //Anzeige des Arrays
}