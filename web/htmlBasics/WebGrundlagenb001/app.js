const express = require("express");
var path = require("path");
const app = express();
const port = 5050;
//Static file server bla bla
app.use(express.static("src"));
app.set("view engine", "pug");

app.get('/404.html', function (req, res) {
    res.statusCode = 404;
    res.sendFile(path.join(__dirname + "/src/error404.html"));
})

app.use(function (req, res, next) {
     res.redirect('/404.html');
});

app.listen(port, () => console.log(`Server listening on port ${port}!`));
