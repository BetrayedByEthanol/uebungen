### Was ist ein Compiler?
Ein Compiler ist das Bindeglied zwischen dem vom Entwickler geschriebenen Code und dem Computer. 
Er übersetzt die ihm bekannte Programmiersprache (zB gcc für C) in den vom Computer lesbaren Maschinencode. Desweiteren überprüft er ob der Code Fehler enthält.

### Was kann gcc?

gcc steht für GNU Compiler Collection und bietet neben der direkten C/C++/C-object auch noch um mehrere Erweiterungen erweitertert werden. Unter anderem gibt es noch Fortran, Ada, Go und D inklusive der zugehörigen Libraries.

### Was für Alternativen gibt es zu gcc?

Zu den Alternativen zählt unter anderem TCC und LLVM.

### Was kann printf()?

Die Funktion nimmt eine Zeichenkette mit Text und Formatierungshinweisen sowie einem oder mehreren Werten entgegen. Die Zeichenkette wird ausgegeben und dabei die Werte in der entsprechenden Formatierung (Schreibweise) eingefügt.

### Welche Datentypen gibt es in C?

In C lassen sich die Datentypen auf `int` `float` `char` und `void` herunterbrechen, mit einigen Abstufungen (zB `long int` bei `int` oder `double` bei `float`).

### Wie sind Strings in C definiert?

Strings in C werden als Char-Array(Zeichenkette) definiert. Das bedeutet das Sätze oder ähnliches als nicht beliebige Zeichenkette definiert sind. Ein Wort ist eine Kette wobei jeder Buchstabe Zahl der Reihenfolge nach zugeordnet wird.
Daher wird das Wort "Wort" umgedacht als 
1. W
2. o
3. r
4. t
gespeichert.
Ich kann dann mit `printf` auf Alles mit `%s` oder auf Einzelnes mit `%c` zugreifen.


