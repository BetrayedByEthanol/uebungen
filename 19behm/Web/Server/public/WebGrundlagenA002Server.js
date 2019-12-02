const express = require("express");
const app = express();

app.get("/Server/public", function (req, res) {
    res.sendfile('cheatsheet.html');

});

app.get("/Server/contact", function(req, res) {
    res.send('Author: Julius Behm');
});

app.listen(3000, () => console.log('Listening on Port 3000'));