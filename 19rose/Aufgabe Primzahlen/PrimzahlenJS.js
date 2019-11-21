console.log("Dieses Programm berechnet die ersten 100 Primzahlen!");
var primzaehler = 100;
var primgezaehltes = 0;
var primmenge = [100];
var n = 0;
for(var i = 2; primgezaehltes < primzaehler; i++) {
    if(primtrue(i, i - 1) == 0) {
        primmenge[n] = i;
        primgezaehltes ++;
        n ++;
    }
}
for(var i = 0; i < 100; i++) {
    console.log("Primzahl Nr. " + (i + 1) + ": " + primmenge[i]);
    if(((i + 1) % 5) == 0) {
        console.log("\n");
    }
}

function primtrue(z1, z2) {
    if(z1 == 1) return 0;
    else if(z2 == 1) return 1;
    else if((z1 % z2) == 0) return 0;
    else return primtrue(z1, z2 - 1);
}