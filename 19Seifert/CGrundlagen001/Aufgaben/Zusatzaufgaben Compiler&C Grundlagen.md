#Zusatzaufgaben
##Compiler
Compiler kommt aus dem Englischen und heißt so viel wie zusammentragen. Er ist dafür da, dass die Programmiersprache eines Quellcodes so übersetzt wird, dass der Computer das Programm ausführen kann. Dabei werden verschiedene Schritte durchgegangen:

- Bei der *Syntaxprüfung* wird überprüft, ob mit dem bestehenden Quellcode ein gültiges Programm entstehen würde. Dabei werden festgestellte fehler protokolliert und eine Zwischendarstellung des Quellcodes wird dargestellt.
- Bei der *Analyse und Optimierung* wird diese Zischendarstellung dann analysiert und optimiert. Der Umfang dieses Schrittes kann sich von Compiler zu Compiler, sowie deren Benutzereinstellungen, von Effizienzoptimierung bis zur Programmanalyse bewegen.
- Schließlich wird die optimierte Zwischendarstellung in die entsprechenden Befehle der Zielsprache übersetzt. Diesen Schritt nennt man *Codeerzeugung* 

Die **GNU Compiler Collection** (kurz GCC) ist eine Sammlung von Compilern, die für die Sprachen C, C++, Objective-C, D, Fortran, Ada und Go nutzbar sind. Es wird als Standartcompiler für viele Linuxdistributionen, BSD-Varianten, Nextstep, BeOS und Zeta. Das kommando, um GCC zu nutzen ist gcc.

Alternativen zu GCC wären zum Beispiel TCC, LLVM oder OTCC.

##C Grundlagen
Der Befehl ```printf()```ist in der stdio.h library enthalten und sorgt dafür da, dass die char, string, float, integer, octal und hexadezimel Werte im Ausgabewerk angezeigt werden. Die Darstellung ```printf(%d)``` spezifiziert, dass es sich im Ausgabewert um einen Integer, also eine ganze Zahl handelt. Ähnlich dazu speizifizieren:

- ```printf(%c)``` einen char, also ein beliebiges Zeichen
- ```printf(%f)``` einen float, also eine reelle Zahl (mit bis zu 7 Stellen)
- ```printf(%s)``` einen string, also eine aneinanderreihung beliebiger Zeichen
- ```printf(%lf)``` einen langen float, also ein float mit mehr Zeichen (mit bis zu 19 Stellen)
- ```printf(%x)``` eine hexadezimale Variable

Type |	Keyword |	Bytes |	Range
:---|:---|:---|:---
character| 	char| 	1 |	-128 .. 127
unsigned character| 	unsigned char |	1| 	0 .. 255
integer |	int |	2 |	-32 768 .. 32 767
short integer |	short 	|2 |	-32 768 .. 32 767
long integer |	long |	4 |	-2 147 483 648 .. 2 147 483 647
unsigned integer |	unsigned int |	2 |	0 .. 65 535
unsigned short integer| 	unsigned short |	2  |	0 .. 65 535
unsigned long integer |	unsigned long |	4 |	0 .. 4 294 967 295
single-precision floating-point (7 Stellen) |	float |	4 |	1.17E-38 .. 3.4E38
double-precision floating-point (19 Stellen) |	double |	8 |	2.2E-308 .. 1.8E308