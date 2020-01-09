#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int add(int zahl, int zahl2)
{
    return(zahl + zahl2);
}

int sub(int zahl, int zahl2)
{
    return(zahl - zahl2);
}

int multp(int zahl, int zahl2)
{
    return(zahl * zahl2);
}

int divi(int zahl, int zahl2)
{
    return(zahl / zahl2);
}

int pot(int zahl, int potency)
{
    int pot;
    pot = zahl;
    potency = potency - 1;
    while(potency > 0)
    {
        pot = pot * zahl;
        potency = potency - 1;
    }
    return(pot);
}

int minmax(int a, int b)
{
    if(a > b)
    {
        printf("Hoeherer Wert: %d\nGeringerer Wert: %d\n", a, b);
    }
    else if(a < b)
    {
        printf("Hoeherer Wert: %d\nGeringerer Wert: %d\n", b, a);
    }
    else if(a == b)
    {
        printf("Ihre beiden Werte %d und %d stimmen ueberein.\n", a, b);
    }
    return 0;
}

double round(double zahl)
{
    double rounded, rest, zahlsave;
    zahlsave = zahl;
    if(zahl > 0)
    {
        while(zahl > 1)
        {
            zahl--;
        }
        rest = zahl;
    }
    else if(zahl < 0)
    {
        while(zahl < -1)
        {
            zahl++;
        }
        rest = zahl;
    }
    else if(zahl == 0)
    {
        rest = 0;
    }
    if(rest >= 0.5)
    {
        rounded = zahlsave + 1 - rest;
    }
    else if(rest <= 0.5 && rest > 0)
    {
        rounded = zahlsave - rest;
    }
    else if(rest >= -0.5 && rest < 0)
    {
        rounded = zahlsave - rest;
    }
    else if(rest <= -0.5)
    {
        rounded = zahlsave - 1 - rest;
    }
    else if(rest == 0)
    {
        rounded = 0;
    }
    return(rounded);
}

double sincosinus(double a)
{
    double sincos;
    sincos = sin(a) + cos(a);
    return(sincos);    
}

int auswahl(char calcchar)
{
    switch(calcchar)
    {
        case '+':
            printf("Ausgewaehlte Rechenart: Addition.\n");
            return 1;
            break;
        case '-':
            printf("Ausgewaehlte Rechenart: Subtraktion.\n");
            return 2;
            //printf("%d\n", calc); Kontrolle
            break;
        case '*':
            printf("Ausgewaehlte Rechenart: Multiplikation.\n");
            return 3;
            break;
        case ':':
            printf("Ausgewaehlte Rechenart: Division.\n");
            return 4;
            break;
        case '^':
            printf("Ausgewaehlte Rechenart: Potenzieren.\n");
            return 5;
            break;
        case '?':
            printf("Ausgewaehlt: Vergleich.\n");
            return 6;
            break;
        case '~':
            printf("Ausgewaehlt: Sinus/Kosinus.\n");
            return 7;
            break;
        case 'r':
            printf("Ausgewaehlt: Runden.\n");
            return 8;
            break;
        }
}

int calculate(int calc)
{
    //calc = 1: Addition, 2: Subtraktion, 3: Multiplikation, 4: Division, 5: Potenzieren, 6: Vergleich, 7: Sinus/Kosinus
    int a, b, ergebnis;
    double ad, sinus, cosinus, sico;
    double rounded, toround;
    if(calc == 1)
    {
        printf("Bitte geben Sie die erste Zahl, mit der gerechnet werden soll, ein.\n");
        scanf("%d", &a);
        printf("Bitte geben Sie die zweite Zahl, mit der gerechnet werden soll, ein.\n");
        scanf("%d", &b);
        ergebnis = add(a, b);
        printf("Ergebnis: %d + %d = %d\n", a, b, ergebnis);
        return ergebnis;
    }
    else if(calc == 2)
    {
        printf("Bitte geben Sie die erste Zahl, mit der gerechnet werden soll, ein.\n");
        scanf("%d", &a);
        printf("Bitte geben Sie die zweite Zahl, mit der gerechnet werden soll, ein.\n");
        scanf("%d", &b);
        ergebnis = sub(a, b);
        printf("Ergebnis: %d - %d = %d\n", a, b, ergebnis);
        return ergebnis;
    }
    else if(calc == 3)
    {
        printf("Bitte geben Sie die erste Zahl, mit der gerechnet werden soll, ein.\n");
        scanf("%d", &a);
        printf("Bitte geben Sie die zweite Zahl, mit der gerechnet werden soll, ein.\n");
        scanf("%d", &b);
        ergebnis = multp(a, b);
        printf("Ergebnis: %d * %d = %d\n", a, b, ergebnis);
        return ergebnis;
    }
    else if(calc == 4)
    {
        printf("Bitte geben Sie die erste Zahl, mit der gerechnet werden soll, ein.\n");
        scanf("%d", &a);
        printf("Bitte geben Sie die zweite Zahl, mit der gerechnet werden soll, ein.\n");
        scanf("%d", &b);
        ergebnis = divi(a, b);
        printf("Ergebnis: %d / %d = %d\n", a, b, ergebnis);
        return ergebnis;
    }
    else if(calc == 5)
    {
        printf("Bitte geben Sie die erste Zahl, mit der gerechnet werden soll, ein.\n");
        scanf("%d", &a);
        printf("Bitte geben Sie die zweite Zahl, mit der gerechnet werden soll, ein.\n");
        scanf("%d", &b);
        ergebnis = pot(a, b);
        printf("Ergebnis: %d ^ %d = %d\n", a, b, ergebnis);
        return ergebnis;
    }
    else if(calc == 6)
    {
        printf("Bitte geben Sie die erste zu vergleichende Zahl an.\n");
        scanf("%d", &a);
        printf("Bitte geben Sie die zweite zu vergleichende Zahl an.\n");
        scanf("%d", &b);
        minmax(a, b);
        return 0;
    }
    else if(calc == 7)
    {
        printf("Bitte geben Sie die Zahl, zu der Sie Sinus und Kosinus wuenschen, an.\n");
        scanf("%lf", &ad);
        sico = sincosinus(ad);
        sinus = sico - cos(ad);
        cosinus = sico - sin(ad);
        printf("sin(%lf): %lf\ncos(%lf): %lf\n", ad, sinus, ad, cosinus);
        return 0;
    }
    else if(calc == 8)
    {
        printf("Bitte geben Sie die Zahl, die Sie zu runden wuenschen, an.\n");
        scanf("%lf", &toround);
        rounded = round(toround);
        printf("Ihre Zahl %lf gerundet: %lf\n", toround, rounded);
        return 0;
    }

}

int contin(int choice)
{
    int r;
    switch(choice)
    {
        case 1:
            r = 1;
            break;
        case 2:
            r = 0;
            break;
    }
    return r;
}

int askcont(void)
{
    int choice;
    printf("Weitere Rechnung(en) anstellen? Y = 1/N = 2\n");
    //printf("SAAL\n"); //test
    scanf("%d", &choice);
    //printf("SAAL\n"); //test
    if(choice == 1)
    {
        return choice;
    }
    else if(choice == 2)
    {
        return choice;
    }
}

int calculator(void)
{
    int repeat = 1, calc, choice;
    char calcchar;
    while(repeat == 1)
    {
        printf("Bitte waehlen Sie die gewuenschte Rechenart aus.\nMoegliche Rechenarten sind: Addition ('+'), Subtraktion ('-'),\nMultiplikation ('*'), Division (':') und Potenzieren ('^').\nDes Weiteren koennen Sie zwei Zahlen vergleichen ('?')\nund den Sinus und Kosinus einer Zahl ausgeben lassen ('~')\n und eine Zahl runden ('r').\n");
        scanf(" %c", &calcchar);

        calc = auswahl(calcchar);

        calculate(calc);

        choice = askcont();
        repeat = contin(choice);
    }
    return 0;
} 

int grkl(int winkel)
{
    int winkell, winkels;
    if(winkel > 180)
    {
        winkell = winkel;
        winkels = 360 - winkel;
    }
    if(winkel < 180)
    {
        winkels = winkel;
        winkell = 360 - winkel;
    }
    printf("Der Winkel zwischen Minuten- und Stundenzeiger beträgt %d bzw %d (Gr. Winkel / Kl. Winkel) Grad.\n", winkell, winkels);
    return(winkel);
}

int pointerangle(void)
{
    int stundenzeiger, minutenzeiger, stdwinkel, mntwinkel, winkel, stundenfortschritt, angefstd;

    printf("Bitte geben Sie die Position (Uhrzeit) des Stundenzeigers an.\n");
    scanf("%d", &stundenzeiger);

    if(stundenzeiger > 12){
        stundenzeiger = stundenzeiger - 12;
    }

    printf("Bitte geben Sie die Position (Uhrzeit) des Minutenzeigers an.\n");
    scanf("%d", &minutenzeiger);
    mntwinkel = minutenzeiger * 6;

    stundenfortschritt = minutenzeiger * 100 / 60;
    angefstd = 30 * stundenfortschritt / 100;
    stdwinkel = stundenzeiger * 5 * 6 + angefstd;

    if(stdwinkel < mntwinkel){
        winkel = mntwinkel-stdwinkel;
        grkl(winkel);
        return(winkel);
    }else if(stdwinkel > mntwinkel){
        winkel = stdwinkel - mntwinkel;
        grkl(winkel);
        return(winkel);
    }else if(stdwinkel == mntwinkel){
        winkel = mntwinkel - stdwinkel;
        grkl(winkel);
        return(winkel);
    }

}

void search(void)
{
    int suche, check;
    check = 0;

    printf("Sollten Sie noch nicht zaehlen koennen:\nBitte geben Sie eine Zahl, nach der gesucht werden soll, an.\n");
    scanf("%d", &suche);

    while(suche > check)
    {
        printf("%d\n", check);
        check = check + 1;
    }

    printf("Gefunden! Gesuchte Zahl: %d\n", suche);

} 

void simulation(int timeup, int timedown, int sunsensitivity, int senact, int sendeact)
{
    int timer = 0, senspan, r, getlvl, sensor;
    int lvl;
    srand(time(0));

    senspan = 100 / sunsensitivity;

    for(timer = 0; timer <= 24; timer++)
    {
        r = rand() % 100;
        if(timer == timeup)
        {
            lvl = sunsensitivity;
        }
        if(timer == timedown)
        {
            lvl = 0;
        }
        if(timer == senact)
        {
            sensor = 1;
        }
        if(timer == sendeact)
        {
            sensor = 0;
        }
        if(sensor == 1)
        {
            getlvl = r / senspan;
            lvl = getlvl;
        }

        printf("Zeit: %d:00 Uhr", timer);
        if(sensor == 1)
        {
            printf(", Sonnensensor: aktiviert, Einstrahlung: %d Prozent", r);
        }
        printf(", Jalousie: Level %d\n", lvl);
    }

}

void config(void)
{
    int timeup, timedown, sunsensitivity, senact, sendeact;
    int boolean = 0, check = 1, start = 0, contin = 1;
    char askcontin;
    //simulation(8, 22, 5, 10, 20);
    while(contin == 1)
    {
        if(boolean == 1)
        {
            printf("Werte aendern? Y = 1 / N = 0\n");
            scanf("%d", &check);
        }
        if(check == 1)
        {
            printf("\nBitte geben Sie die Stundenzahl an, zu der ihre Jalousie hochfahren soll.\n");
            scanf("%d", &timeup);
            printf("\nBitte geben Sie die Stundenzahl an, zu der ihre Jalousie hinunterfahren soll.\n");
            scanf("%d", &timedown);
            printf("\nBitte geben Sie die Sensitivitaet an, mit der ihr Sonnensensor bei Aktivierung agieren soll.\n");
            scanf("%d", &sunsensitivity);
            printf("\nBitte geben Sie die Stundenzahl an, zu der ihr Sensor aktiviert werden soll.\n");
            scanf("%d", &senact);
            printf("\nBitte geben Sie die Stundenzahl an, zu der ihr Sensor deaktiviert werden soll.\n");
            scanf("%d", &sendeact);
            check = 0;
        }
        /*else if(check == 2)
        {
            contin--;
        }*/

        printf("Simulation starten? Y = 1 / N = 0\n");
        scanf("%d", &start);

        if(start == 1)
        {
            simulation(timeup, timedown, sunsensitivity, senact, sendeact);
        }

        boolean = 1;

        //fflush(stdin);

        printf("Fortfahren? Y / N\n");
        scanf(" %c", &askcontin);
        switch(askcontin)
        {
            default:
                contin--;
                break;
            case 'Y':
                break;
        }

    }
}

void helloworld() 
{
	printf("Hello World\n");
}

int main(void)
{
    char choicechar, choicee;
    int repeat = 1, repyn;

    printf("Herzlich Willkommen bei FIAN(C)onnect ©!\nFIANC © bietet Ihnen alles, was Sie nicht brauchen werden und mehr oder weniger nicht mehr!\nDavon aber dafuer ganz schoen viel! Wir freuen uns,\ndass Sie sich fuer FIANC © entschieden haben. :)\n");

    while(repeat == 1)
    {
        printf("Momentan koennen wir von FIANC © Ihnen folgende Potentials bieten:\nPotential 1 ('T'): Taschenrechner\nPotential 2 ('Z'): Winkelberechnung zweier Uhrzeiger\nPotential 3 ('S'): Suche nach einer positiven Zahl von 0 an in Ganzzahlschritten\nPotential 4 ('J'): Konfiguration & Simulation einer Jalousie-Steuerung\nPotential 5 ('H'): !NUR FUER FORTGESCHRITTENE USER! Ausgabe eines sog. 'Hello World'\n"); //REMINDER: Add Erlaeuterungen
        scanf(" %c", &choicechar);

        switch(choicechar)
        {
            case 'T':
                choicee = 1;
                break;
            case 'Z':
                choicee = 2;
                break;
            case 'S':
                choicee = 3;
                break;
            case 'J':
                choicee = 4;
                break;
            case 'H':
                choicee = 5;
                break;
        }

        if(choicee == 1)
        {
            calculator();
        }
        if(choicee == 2)
        {
            pointerangle();
        }
        if(choicee == 3)
        {
            search();
        }
        if(choicee == 4)
        {
            config();
        }
        if(choicee == 5)
        {
            helloworld();
        }

        printf("Moechten Sie weitere Potentials erreichen? (Y: Eingabe 1 / N: Eingabe 2)\n");
        scanf("%d", &repyn);

        /*switch(repyn)
        {
            case 'Y':
                break;
            case 'N':
                repeat = 0;
                break;
        }*/

        if(repyn == 2)
        {
            repeat = 0;
        }

    }
    return 0;
} 
