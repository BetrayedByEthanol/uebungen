const express = require('express');
const app = express();
const port = 5050;
//Static file server
app.use(express.static('src'));
app.listen(port, () => console.log(`Server listening on port ${port}!`));