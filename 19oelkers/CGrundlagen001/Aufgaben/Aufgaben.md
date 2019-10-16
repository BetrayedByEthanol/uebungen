# Aufgaben

#### 1

Ein Compiler ist ein Quelltext zu Machinecode Übersetzer meist mit integrierter Fehler Analyse.


#### 2

Die GNU Compiler Collection bietet Compiler für die Programmiersprachen:

C, C++, Objective-C, D, Fortran, Ada und Go.

gcc unterliegt dem GNU was auf ewig einen Kostenfreien zugang gewehrt.


#### 3

Alternativen zu gcc währen z.B. TCC ( Tiny C Compiler ) und
OTCC( Obfuscated Tiny C Compiler )
<br>
<br>
<br>

#### 4

Was kann ich mit printf() alles machen.

    int age;
    age = 20;
    
    printf ( "Kann benutzt werden um z.B. hier %d durch den wert von age zu ersetzten", age)

Plus signs
    ("%+5d",0) +0
    ("%+5d",-7) -7
    ("%+5d",1560133635) +1560133635
    ("%+5d",-2035065302) -2035065302

Filling Extra Space
(***27 or 27***or **27*)

Plus, Space, and Zero
    ("% 05d",0) 0000
    ("% 05d",-7) -0007
    ("% 05d",1560133635) 1560133635
    ("% 05d",-2035065302) -2035065302
