var login = function () {
  console.log();
  var user = document.getElementById('login').value;
  var pass = document.getElementById('password').value;

  console.log(JSON.stringify({
    username: user,
    password: pass
  }))
  fetch('/login', {
    method: "POST",
    headers: {
      'Accept': 'application/json',
      'Content-Type': 'application/json'
    },
    body: JSON.stringify({
      username: user,
      password: pass
    })
  }).then(res => {
    var text = res.text();
    text.then((result) => {
      let data = JSON.parse(result);
      var date = new Date(data.tokenExpirationDate);
      document.cookie = 'logTok=' + data.token + '; expires=' + date.toUTCString() + ';';
      document.cookie = 'user=' + data.username + '; expires=' + date.toUTCString() + ';'; 
      window.location.href = '../';
    })
  });
}