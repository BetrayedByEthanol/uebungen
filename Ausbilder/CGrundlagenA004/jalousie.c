#include<stdio.h>
#include<stdbool.h>

//zeitangaben
int minuten = 20;		//die fortlaufenden Minuten pro Tag
int minutesProTag = 0;	//die kompletten Minuten pro Tag
int startTag = 0;		
int startNacht = 0;
int stundenMorgen;
int minutenMorgen;
int stundenAbend;
int minutenAbend;

bool tag = false;

//Stellung der Jalousie, der Ober- und Untergrenzen, sowie des Sonnensensors
int posOben = 100;
int posUnten = 0;
int posJalousie = 0;				//0 entspricht unten, 100 entspricht oben, der Wert dazwischen wäre die Position des Sonnensensors;
int posSonnensensor1 = 65;
int posSonnensensor2 = 67;


//Intensität der Sonneneinstrahlung
int intenseSonneSchwellwert = 65;
int intenseSonneneinstrahlung = 54;


void main()
{
	// Eingaben
	minutesProTag = 24 * 60;
	printf("Gebe die Stunde ein, wann die Jalousie morgens hochfahren soll: ");
	scanf("%d",&stundenMorgen);
	printf("Trage nun auch die Minuten fuer morgens ein: ");
	scanf("%d",&minutenMorgen);
	printf("Gebe nun die Stunde an, wann die Jalousie abends herunterfahren soll: ");
	scanf("%d",&stundenAbend);
	printf("Auch hier bitte die Minute noch angeben: ");
	scanf("%d",&minutenAbend);
	printf("Letzte Eingabe. In welcher Hoehe zwischen 10 und 90 soll der Sonnensensor stehen? ");
	scanf("%d",&posSonnensensor1);
	
	// Fehleingaben abfangen
	if(stundenMorgen > 12 || stundenMorgen < 0)
	{
		if(stundenMorgen > 12)
		{
			stundenMorgen = 12;
		}
		else
		{
			stundenMorgen = 1;
		}		
	}
	
	if(minutenMorgen > 59 || minutenMorgen < 0)
	{
		if(minutenMorgen > 59)
		{
			minutenMorgen = 59;
		}
		else
		{
			minutenMorgen = 1;
		}
	}
	
	if(stundenAbend > 23 || stundenAbend < 13)
	{
		if(stundenAbend > 23)
		{
			stundenAbend = 23;
		}
		else
		{
			stundenAbend = 13;
		}
	}
	
	if(minutenAbend > 59 || minutenAbend < 0)
	{
		if(minutenAbend > 59)
		{
			minutenAbend = 59;
		}
		else
		{
			minutenAbend = 0;
		}
	}
	
	if(posSonnensensor1 > 90 || posSonnensensor1 < 10)
	{
		if(posSonnensensor1 > 90)
		{
			posSonnensensor1 = 90;
		}
		else
		{
			posSonnensensor1 = 10;
		}
	}
	
	//Umrechnung stunde - minute morgens und abends
	startTag = minutenMorgen + (stundenMorgen * 60);
	startNacht = minutenAbend + (stundenAbend * 60);
		
	
	if(minuten < startTag || minuten > startNacht)		//überprüfen ob es tags ist
	{
		tag = false;
	}
	else
	{
		tag = true;
	}
	
	if(tag)
	{
		if(minuten == startTag)		// wenn es morgens ist
		{
			for(int i = 0; i < posOben; i++)
			{
				posJalousie = i;
			}
		}		
		else
		{
			//hier kommt die Somnnensteuerung
			if(intenseSonneneinstrahlung >= intenseSonneSchwellwert)
			{
				while(posJalousie > posSonnensensor1)
				{
					posJalousie--;
				}
			}
			else
			{
				while(posJalousie < posOben)
				{
					posJalousie++;
				}				
			}
		}
	}
	else if(minuten == startNacht)	// wenn es abends ist
	{
		for(int i = posJalousie; i > posUnten; i--)
		{
			posJalousie--;
		}
		
		if(minuten > minutesProTag)
		{
			minuten = 0;
		}
	}	
}