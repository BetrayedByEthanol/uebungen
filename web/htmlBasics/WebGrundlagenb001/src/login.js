var login = function(){
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
              console.log(data.token);
              document.cookie = 'logTok='+data.token;
          })
      });
    }