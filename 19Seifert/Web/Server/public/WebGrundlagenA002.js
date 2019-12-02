const express = require('express');
const app = express();



app.get('/server/public', function(req, res) {
    res.sendfile('cheatsheet.htm');
});

app.listen(3000, () => console.log('Listening on port 3000'))