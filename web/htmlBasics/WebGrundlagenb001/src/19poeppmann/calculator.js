function zahl(){
    var zahl1, zahl2, operator , ergebnis;
    zahl1 = prompt("Geben Sie eine Zahl an");
    operator = prompt("Geben sie einen Operator an + für Addition - für Subtraktion * für das Multiplizieren / für das Dividieren und ^ für das Potenzieren");
    zahl2 = prompt("Geben Sie eine weitere Zahl an")

switch (operator) {
    case '+':
        ergebnis = (Number(zahl1)+Number(zahl2));
      // Anweisungen werden ausgeführt,
      // falls expression mit plus übereinstimmt
      break;
    case '-':
        ergebnis = (Number(zahl1)-Number(zahl2));
      // Anweisungen werden ausgeführt,
      // falls expression mit min übereinstimmt
      break;
    case '*':
        ergebnis = (Number(zahl1)*Number(zahl2));
      // Anweisungen werden ausgeführt,
      // falls expression mit mul übereinstimmt
      break;
    case '/':
        ergebnis = (Number(zahl1)/Number(zahl2));
      // Anweisungen werden ausgeführt,
      // falls expression mit div übereinstimmt
      break;

    case '^':
        ergebnis = (Number(zahl1)**Number(zahl2));
      break;
    default:
        alert("Kein Operator")
      // Anweisungen werden ausgeführt,
      // falls keine der case-Klauseln mit expression übereinstimmt
      break;
  }
  alert (ergebnis);
}
