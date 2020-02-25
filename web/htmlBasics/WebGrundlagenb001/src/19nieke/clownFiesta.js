
function calc(rating, lastViewsDifference, timesDisplayed) {
    const BaseProbability = 1;
    var ratingModifier = 1;
    var lastViewModifer = 1;
    var timesDisplayedModifier = 1;
    for(var i = 1; i <= Math.abs(rating); i++) {
        ratingModifier += Math.pow(0.5,i);
    }
    
    if (rating < 0) ratingModifier = 1 / ratingModifier;

    for(var i = 1; i <= Math.abs(lastViewsDifference); i++) {
        lastViewModifer += Math.pow(0.4,i);
    }

    for(var i = 1; i <= Math.abs(timesDisplayed); i++) {
        timesDisplayedModifier += Math.pow(0.2,i);
    }
    timesDisplayedModifier = 1 / timesDisplayedModifier;

    const prob = BaseProbability * ratingModifier * lastViewModifer * timesDisplayedModifier;
    console.log('total probabilty: ' + prob);
    console.log('rating mod: ' + ratingModifier);
    console.log('last view mod: ' + lastViewModifer);
    console.log('times displayed mod: '+ timesDisplayedModifier);
}

function altSort(rating, lastViewsDifference, timesDisplayed) {
    let data = []
    for( i = 0; i < 150 ; i++) data.push("strategie number " + (i + 1) );
    console.log(data);
}