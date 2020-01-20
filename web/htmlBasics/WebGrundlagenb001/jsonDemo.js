
let quotes =  {
    "author": {
        "name": "J.K. Rowling",
        "origin": "Wales",
        "alive": true,
        "gender": "female"
    },
    "quote": "It does not do to dwell on dreams and forget to live.",
    "tags": ["Harry Potter", "Movies", "Books", "England"]
};

console.log(quotes.tags);


quotes.tags.forEach((item,index) => console.log(item + ' ' + index));



