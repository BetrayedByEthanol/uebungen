const express = require('express')
const app = express()
const port = 3000

app.get('/server/public', (request, response) => {
    response.sendfile('cheatsheet.html')
});

app.listen(port, (err) => {
    if (err) {
        return console.log('something bad happened', err)
}

console.log(`server is listening on ${port}`)
})