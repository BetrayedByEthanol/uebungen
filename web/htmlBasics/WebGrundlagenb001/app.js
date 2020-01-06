const express = require("express");
var path = require("path");
var morgan = require('morgan');
const app = express();
const port = 5050;

app.use(morgan('common'));
app.use(express.static("src"));

app.use(function (req, res, next) {
    res.statusCode = 404;
    res.sendFile(path.join(__dirname + "/src/error404.html"));
});

app.listen(port, () => console.log(`Server listening on port ${port}!`));
