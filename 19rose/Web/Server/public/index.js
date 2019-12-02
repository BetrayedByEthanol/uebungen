const express = require('express');
const index = express();

index.get('/', function (req, res) {
    res.sendfile('cheatsheet.html');
});

index.listen(3000, function(){
    console.log('Dienste sind nun auf Port 3000 online');
});