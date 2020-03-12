var register = function () {
    console.log();
    var username = document.getElementById('name').value;
    var pass = document.getElementById('password').value;
    var email = document.getElementById('email').value;
    var pass2 = document.getElementById('confirm').value;
    console.log(JSON.stringify({
        username: username,
        email: email,
        password: pass,
        password2: pass2
    }));
    fetch('/register', {
        method: "POST",
        headers: {
            'Accept': 'application/json',
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({
            username: username,
            email: email,
            password: pass,
            password2: pass2
        })
    }).then(res => {

        var text = res.text();
        text.then((result) => {
            console.log(result);
            let data = JSON.parse(result);
            var date = new Date(data.tokenExpirationDate);
            document.cookie = 'logTok=' + data.token + '; expires=' + date.toUTCString() + ';';
            document.cookie = 'user=' + data.username + '; expires=' + date.toUTCString() + ';';
            window.location.href = '../';
        });
    });
}