# Einführung JAVA

## 1. Beschreiben Sie die Aufgabe eines Interpreters und seine Vorteile/Nachteile
Die Aufgabe eines Interpreters besteht darin, den Code in Maschinencode zu übersetzen, ähnlich eines Compilers. Allerdings liest er den Code nicht als ganzes, um ihne optimiert zu übersetzten sondern Zeile für Zeile. Als Nachteile stellen sich dabei in den Fordergrund die Geschwindigkeit, die Fehlerüberprüfung und die Analyse und Optimierung. Langsamer ist er deshalb, da Befehl für Befehl ausgeführt wird. Durch das fehlen der Syntaxprüfung eines Compilers werden Fehler erst gefunden, wenn ein Befehl aufgerufen wird, bis dahin läuft alles fehlerlos. Der große Vorteil ist, dass der interpretierte Code unabhängig von der CPU bzw dem System ist.

## 2. Erklären Sie, weshalb man sich bei Java für ein Hybridsystem aus Compiler und Interpreter entschieden hat.

Bei Java hat man sich für eine Hybridlösung entschieden weil die Kompatibilität immer im Vordergrund stand. Der Code wird vom Compiler, welcher in der Java VM enthalten ist in Bytecode übersetzt welcher dann vom enthaltenen Interpreter interpretiert wird. Dadurch kann auf jedem Gerät, welches die JavaVM unterstützt Java-Code ausgeführt werden. 
Der geschriebene Code wird vom Compiler gelesen, welcher alle Vorteile hat wie jeder Compiler auch (Fehlersuche) und in Bytecode übersetzt, welcher der Maschinensprache so ähnlich ist, dass der Interpreter kaum mehr Zeit benötigt um den Code zu interpretieren. Das liegt vor allem an der hohen Optimierung der Java VM. 

## 22.1.2 Linker/Binder

**Was ist das?:** Ein Linker ist ein Programm, welches einzelne Module zu einem ausführbaren Programm verbindet. 

**Funktion:** Der Linker erhält die compilierten Codes der verschiedenen Module und die eingebundenen Bibliotheken und verbindet sie zum vollständigen Programm. Dies kann statisch (meist nur eine Exe) oder dynamisch (exe + zB dll (dynamische Bibliothek)) stattfinden.

**Vertreter bei Java:** In Java gibt es an sich keinen Linker. Eine ähnliche Aufgabe übernimmt allerdings der Classloader, der, solange es ein Bytecodearray von irgendwoher gibt, eine interne Version dieses erstellen kann welche mit ``new`` verwendet werden kann.

## 22.1.3 Skriptsprache

Die eigentliche Antwort heutzutage ist **NEIN!** es gibt keine Unterschiede. Die Linie zwischen den beiden Spracharten ist mittlerweile sehr verschwommen.  Vorher waren Scriptsprachen eher dazu gedacht bereits existierende Anwendungen zu steuern während bei Programmiersprachen Anwendungen aus dem nichts erschaffen wurden. 