# LF3/4

## Was ist eine digitale Signatur?

Eine digitale Signatur ist eine Möglichkeit die Echtheit eines Dokumentes zu bestätigen. Dabei wird das Dokument mit einem, durch den **privatem** Schlüssel verschlüsselten Datenblock versehen, welcher nur mit dem zu einem gehörenden öffentlichen Schlüssel wieder entfernt werden kann. Dadurch wird bewiesen, dass man der Urheber eines Dokuments ist, ähnlich eines Wasserzeichens.

## Wie funktioniert die symmetrische Verschlüsselung?

Im ersten Schritt einigen sich beide Computer auf den öffentlichen Schlüssel, mit welchem das Dokument verschlüsselt wird/wurde. Danach wird das Dokument versandt und danach kann das Dokument wieder entschlüsselt werden. Der vorgang geht relativ schnell, kann aber abgegriffen werden, da der Schlüssel selbst auch übertragen wird. Falls dieser abgegriffen wird, kann alles andere, was danach kommt auch abgegriffen werden.

## Wie funktioniert die asymmetrische Verschlüsselung?

Bei der asymmetrischen Verschlüsselung sendet ein Computer seinen öffentlichen Schlüssel an den anderen Computer, welcher die Daten mit diesem veschlüsselt. Die Verschlüsselung kann allerdings nur mit dem privaten Schlüssel des ersten Computers wieder aufgehoben werden, wodurch der Vorgang sehr sicher ist. Allerdings dauert er im Vergleich zur symmetrischen Verschlüsselung auch wesentlich länger.

## Wie funktioniert die hybride Verschlüsselung?

Die hybride Verschlüsselung bildet einen Mittelpunkt zwischen den beiden vorhergehenden Methoden. Hierbei wird das eigentliche Dokument symmetrisch verschlüsselt, allerdings wird der Schlüssel dafür asymmetrisch versandt, weshalb der Vorgang sowohl schnell als auch sicher ist.

## Wo wird Verschlüsselung in der IT eingesetzt?

Bei sogut wie allen Arten der Übertragung von Persondaten oder Dokumenten die geheim bleiben sollen wird Verschlüsselung verwendet. Allerdings auch bei Chats wie Whatsapp etc kommt Verschlüsselung ins Spiel. Stichwort Briefgeheimnis.

## Grenze die drei Begriffe voneinander ab: Kryptologie/Kryptographie/Kryptoanalyse

Kryptologie ist die Wissenschaft der Verschlüsselung. Oberbegriff.
Kryptographie ist befasst sich mit den Methode also der Konzeption Planung und Durchführung von Verschlüsselungen.
Kryptoanalyse befasst sich mit Methoden verschlüsselungen zu knacken.

## Hash-Wert?

Der Hashwert ist eine Prüfsumme fester Länge, die mittels Hashfunktion zur Verschlüsselung einer Nachricht mit variabler Länge angewendet wird.

Entscheidend ist dabei, dass es keine zwei verschlüsselten Nachrichten geben darf, die auf denselben Hashwert zurückzuführen sind. In diesem Fall spricht man von einer Kollision.

Hashwerte sind interessant, weil vom Hashwert aus keine Rückschlüsse auf den Nachrichteninhalt gezogen werden können. Die Länge des Hashwertes ist abhängig vom Verschlüsselungsalgorithmus und liegt beim SHA-Algorithmus bei 160 Bit, beim MD5-Algorithmus bei 128 Bit.

Der Hashwert wird häufig auch als <u>digitaler Fingerprint bezeichnet</u>.

## Wie sicher ist Verschlüsselung? Maßnahmen zur Erhöhung der Sicherheit?

Abhängig von der Art und Weise der Verschlüsselung ist diese sehr sicher. Die asymmetrische Verschlüsselung würde die Sicherste darstellen. Die Sicherheit hängt allerdings vom jeweiligen Nutzer ab. Möglichkeiten zur Erhöhung der Sicherheit, wäre die Verwendung von hybrider Verschlüsselung in Kombination mit weiteren Massnahmen um die Verbindung zu sichern (VPN etc.)

## Was versteht man unter RSA?

RSA ist ein asymmetrisches kryptographisches Verfahren, das sowohl zum Verschlüsseln als auch zum digitalen Signieren verwendet werden kann. Es verwendet ein Schlüsselpaar, bestehend aus einem privaten Schlüssel, der zum Entschlüsseln oder Signieren von Daten verwendet wird, und einem öffentlichen Schlüssel, mit dem man verschlüsselt oder Signaturen prüft. Der private Schlüssel wird geheim gehalten und kann nicht aus dem öffentlichen Schlüssel berechnet werden.
