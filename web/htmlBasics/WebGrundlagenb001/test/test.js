var assert = require("assert");
var chai = require("chai");
chai.use(require("chai-fs"));
var expect = chai.expect;
var tn = ["ausbilder", "19adam", "19behm", "19nieke", "19peters", "19rose", "19seifert", "19soler", "19tantsch", "19zech"];

var path = "src/index.html";
describe("Dateien sind vorhanden", function() {
  describe("19??.html ist vorhanden", function() {
    tn.forEach(element => {
      it(`${element}.html ist vorhanden`, function() {
        expect(`src/${element}.html`).to.be.a.file(element);
      });
    });
  });
});