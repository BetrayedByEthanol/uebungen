const headcount = 5;
var quoten = null;
var kickstarterscript = function () {
    quoten = JSON.parse(hateeteepee.responseText);
    const allee = [0,1,2,3,4,5,6,7,8];
    allee.forEach(numbaa => {
        const dataElement = document.getElementById('coppypasta');
        const id_data = dataElement.cloneNode(false);
        const authorname_data = dataElement.cloneNode(false);
        const quote_data = dataElement.cloneNode(false);
        const tag_data = dataElement.cloneNode(false);
        id_data.innerText = quoten[numbaa].id;
        id_data.className += ' id_data ' + numbaa + ' a' + numbaa;
        id_data.id = 'id' + numbaa;
        authorname_data.innerText = quoten[numbaa].author.name;
        authorname_data.className += ' authorname_data ' + numbaa + ' a' + numbaa;
        authorname_data.id = 'authorname' + numbaa;
        quote_data.innerText = quoten[numbaa].quote;
        quote_data.className += ' quote_data ' + numbaa + ' a' + numbaa;
        quote_data.id = 'quote' + numbaa;
        tag_data.innerText = quoten[numbaa].tags;
        tag_data.className += ' tag_data ' + numbaa + ' a' + numbaa;
        tag_data.id = 'tag' + numbaa;
        const grid = document.getElementById('grid');
        grid.appendChild(id_data);
        grid.appendChild(authorname_data);
        grid.appendChild(quote_data);
        grid.appendChild(tag_data);
        id_data.hidden = false;
        authorname_data.hidden = false;
        quote_data.hidden = false;
        tag_data.hidden = false;
    })
    

}
var order1 = false;
var order2 = false;
var order3 = false;
var order4 = false;
var sort1 = function () {    
    quoten = JSON.parse(hateeteepee.responseText);
    const allee = quoten;
    var test = new Array();
    var uwu = 0;
    allee.forEach(elephant => {
        test[uwu] = new Array();
        test[uwu][0] = elephant.id;
        test[uwu][1] = allee.indexOf(elephant);
        uwu++;
    });
    test.sort((a, b) => {
        const eins = a[0];
        const zwei = b[0];
        const einszahl = eins.length;
        const zweizahl = zwei.length;
        var count = 0;
        while(eins.charCodeAt(count) == zwei.charCodeAt(count)) {
            if((count >= einszahl) && (count >= zweizahl)) {
                return 0;
            } else if(count >= einszahl) {
                return -1;
            } else if(count >= zweizahl) {
                return 1;
            }
            count++;
        }
        if(eins.charCodeAt(count) == zwei.charCodeAt(count)) {
            return 0;
        } else if(eins.charCodeAt(count) > zwei.charCodeAt(count)) {
            return 1;
        } else if(eins.charCodeAt(count) < zwei.charCodeAt(count)) {
            return -1;
        }
    });
    var check = appaly(test, order1);
    order1 = check;
}
var sort2 = function () {
    quoten = JSON.parse(hateeteepee.responseText);
    const allee = quoten;
    var test = new Array();
    var uwu = 0;
    allee.forEach(elephant => {
        test[uwu] = new Array();
        test[uwu][0] = elephant.author.name;
        test[uwu][1] = allee.indexOf(elephant);
        uwu++;
    });
    test.sort((a, b) => {
        const eins = a[0];
        const zwei = b[0];
        const einszahl = eins.length;
        const zweizahl = zwei.length;
        var count = 0;
        while(eins.charCodeAt(count) == zwei.charCodeAt(count)) {
            if((count >= einszahl) && (count >= zweizahl)) {
                return 0;
            } else if(count >= einszahl) {
                return -1;
            } else if(count >= zweizahl) {
                return 1;
            }
            count++;
        }
        if(eins.charCodeAt(count) == zwei.charCodeAt(count)) {
            return 0;
        } else if(eins.charCodeAt(count) > zwei.charCodeAt(count)) {
            return 1;
        } else if(eins.charCodeAt(count) < zwei.charCodeAt(count)) {
            return -1;
        }
    });
    var check = appaly(test, order2);
    order2 = check;
}
var sort3 = function () {
    quoten = JSON.parse(hateeteepee.responseText);
    const allee = quoten;
    var test = new Array();
    var uwu = 0;
    allee.forEach(elephant => {
        test[uwu] = new Array();
        test[uwu][0] = elephant.quote;
        test[uwu][1] = allee.indexOf(elephant);
        uwu++;
    });
    test.sort((a, b) => {
        const eins = a[0];
        const zwei = b[0];
        const einszahl = eins.length;
        const zweizahl = zwei.length;
        var count = 0;
        while(eins.charCodeAt(count) == zwei.charCodeAt(count)) {
            if((count >= einszahl) && (count >= zweizahl)) {
                return 0;
            } else if(count >= einszahl) {
                return -1;
            } else if(count >= zweizahl) {
                return 1;
            }
            count++;
        }
        if(eins.charCodeAt(count) == zwei.charCodeAt(count)) {
            return 0;
        } else if(eins.charCodeAt(count) > zwei.charCodeAt(count)) {
            return 1;
        } else if(eins.charCodeAt(count) < zwei.charCodeAt(count)) {
            return -1;
        }
    });
    var check = appaly(test, order3);
    order3 = check;
}
var sort4 = function () {
    quoten = JSON.parse(hateeteepee.responseText);
    const allee = quoten;
    var test = new Array();
    var uwu = 0;
    allee.forEach(elephant => {
        test[uwu] = new Array();
        test[uwu][0] = elephant.tags.join();
        test[uwu][1] = allee.indexOf(elephant);
        uwu++;
    });
    test.sort((a, b) => {
        const eins = a[0];
        const zwei = b[0];
        const einszahl = eins.length;
        const zweizahl = zwei.length;
        var count = 0;
        while(eins.charCodeAt(count) == zwei.charCodeAt(count)) {
            if((count >= einszahl) && (count >= zweizahl)) {
                return 0;
            } else if(count >= einszahl) {
                return -1;
            } else if(count >= zweizahl) {
                return 1;
            }
            count++;
        }
        if(eins.charCodeAt(count) == zwei.charCodeAt(count)) {
            return 0;
        } else if(eins.charCodeAt(count) > zwei.charCodeAt(count)) {
            return 1;
        } else if(eins.charCodeAt(count) < zwei.charCodeAt(count)) {
            return -1;
        }
    });
    var check = appaly(test, order4);
    order4 = check;
}
var appaly = function (ahray, trueorder) {
    var zahl = 0;
    var step = 1;
    var truhe = false;
    if(trueorder == false) {
        ahray.forEach(elephant => {
            quoten = JSON.parse(hateeteepee.responseText);
            var zzz = elephant[1];
            var rettich = quoten[zzz];
            var rabadon = document.getElementsByClassName('a' + zahl);
            rabadon[0].innerText = rettich.id;
            rabadon[1].innerText = rettich.author.name;
            rabadon[2].innerText = rettich.quote;
            rabadon[3].innerText = rettich.tags;
            zahl = zahl + step;
        });
        zahl = 0;
        step = 1;
        ahray.forEach(elephant => {
            var zzz = elephant[1];
            var rabadon = document.getElementsByClassName('a' + zahl);
            rabadon[3].classList.replace(zahl, zzz);
            rabadon[2].classList.replace(zahl, zzz);
            rabadon[1].classList.replace(zahl, zzz);
            rabadon[0].classList.replace(zahl, zzz);
            zahl = zahl + step;
        });
        truhe = true;
    } else {
        zahl = ahray.length - 1;
        step = -1;
        ahray.forEach(elephant => {
            quoten = JSON.parse(hateeteepee.responseText);
            var zzz = elephant[1];
            var rettich = quoten[zzz];
            var rabadon = document.getElementsByClassName('a' + zahl);
            rabadon[0].innerText = rettich.id;
            rabadon[1].innerText = rettich.author.name;
            rabadon[2].innerText = rettich.quote;
            rabadon[3].innerText = rettich.tags;
            zahl = zahl + step;
        });
    }
    order1 = false;
    order2 = false;
    order3 = false;
    order4 = false;
    return truhe;
}

const hateeteepee = new XMLHttpRequest();
hateeteepee.open("GET", "../data/quotes.json");
hateeteepee.onload = kickstarterscript;
hateeteepee.send()