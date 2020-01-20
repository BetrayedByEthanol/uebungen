
function show_menu(id){
    var menu = document.getElementById(id);
    var  divs = document.getElementsByClassName('hidden_menu');

    Array.from(divs).forEach(div => 
        {
            if(div == menu)
            {
                if(menu.style.display == 'block'){
                    menu.style.display = 'none';
                }else {
                    menu.style.display = 'block';                    
                }
            }
            else div.style.display = 'none';
        });

}  