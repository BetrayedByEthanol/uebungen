
var express = require('express');
var index = express();

index.use('/Server/public',express.static('public'));

index.listen(3000, function () {
  console.log('Example app listening on port 3000!');
});
