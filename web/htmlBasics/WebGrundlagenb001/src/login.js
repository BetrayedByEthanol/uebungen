
var login = function() {
    var http = new XMLHttpRequest();
    var user = document.getElementById('login');
    var pass = document.getElementById('password');
    http.open('POST',  "/login", true);
    http.setRequestHeader('Content-type','json');
    let data = {
        username: user,
        password: pass 
    }
  
    http.send(data);
    http.onreadystatechange = () => {
        var res = http.responseText;
        var obj = JSON.parse(res);
        token = obj.access_token;
    }
}