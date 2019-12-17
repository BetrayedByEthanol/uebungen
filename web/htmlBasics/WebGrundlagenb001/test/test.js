var assert = require("assert");
var chai = require("chai");
chai.use(require("chai-fs"));
var expect = chai.expect;
var tn = ["ausbilder", "19adam", "19behm", "19nieke", "19peters", "19rose", "19seifert", "19soler", "19tantsch", "19zech"];

var path = "src/index.html";
describe("Sind Dateien vorhanden", function() {
  describe("19??.html ist vorhanden", function() {
    tn.forEach(element => {
      it(`${element}.html ist vorhanden`, function() {
        expect(`src/${element}.html`).to.be.a.file("element");
      });
    });
  });
  describe("19??Html5.html ist vorhanden", function() {
    tn.forEach(element => {
      it(`${element}Html5.html ist vorhanden`, function() {
        expect(`src/${element}Html5.html`).to.be.a.file("element");
      });
    });
  });
  describe("19??css.css ist vorhanden", function() {
    tn.forEach(element => {
      it(`${element}css.css ist vorhanden`, function() {
        expect(`src/${element}css.css`).to.be.a.file();
      });
    });
  });
  describe("web/htmlBasic/WebGrundlagenb001/src/19??profil.html ist vorhanden", function() {
    tn.forEach(teilnehmer => {
      it(`${teilnehmer}profil.html`, function() {
        expect(`src/${teilnehmer}profil.html`).to.be.a.file();
      });
    });
  });
});
