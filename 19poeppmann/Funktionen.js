var a;  //globale variable

function multiplizieren (faktora, faktorb){ //Initilisierung einer Funktion mit Parametern
    a = "test";  //setze variabel a zu test
    if (typeof faktora === "number" && typeof faktorb === "number") {  //Prüfung ob faktora und faktorb eine Nummer ist
        return faktora*faktorb; //multiplizierung faktora und faktorb
    } else {
        console.log("Falsche Parameterangabe!"); //Wenn keine Nummer dann...
    }
}