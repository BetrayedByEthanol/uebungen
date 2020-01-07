let quotes = [{
    author: 'Person1',
    quote: 'random quote-text.',
    index: 0
},
{
    author: 'Person2',
    quote: 'random quote-text 2.', 
    index: 1
}]

//console.log(quotes.author);

quotes.forEach(myFunction);

function myFunction(zeug){
    console.log(zeug.author);
}



