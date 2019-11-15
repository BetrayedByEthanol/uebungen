##Sonnenschutz 
#**Die neue Jalousie soll wenn es Nacht wird automaitsch aktiviert werden, sodass sie über Nacht geschlossen bleibt. Am  morgen wird sie automatisch hochgefahren.**
#**Außerdem wird die Jalousie bei starker Sonneneinstrahlung runtergefahren.Und bei geringer Sonnenseinstrahlung hoch gefahren. Die Sonneneinstrahlung wird von einem Sensor gemessen**

##Pseudocode

Sensorvariable = Sonneneinstrahlung
Variable = Wert hoch enstspricht Jalousie zu (bei viel Sonne und Nacht) Wert niedrig entspricht Jalousie offen(bei wenig Sonne und Tag)
Device = eine Variable für die manuelle bedienung

int main(){

    if (Device=1 )
        Variable= 50  //offen
        scanf("%d", Sonnenvariable)
    else if(Device =2)
        {
            Variable  = 100
            scanf("%d", Sonnenvariable)
        }
}


int sensor(int a){
    if(if Sonnensvariable < 50 )
        Device = 1
    else if(Sonnenvariable >= 50)
        Device = 2
}


Bei der App hat der User die möglichlkeit die Jalousie immer wieder auf und zu zuschalten. Oder er behält einen Zustan bei und die App beendet sich.