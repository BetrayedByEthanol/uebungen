var numbers = [2, 1, 5, 4, 3]
var namen = [ "Felix", "Anton", "Emil"]            


numbers.sort((a, b) => a - b); 

namen.sort((a, b)=> {
    return a.localeCompare(b);
});

console.log(numbers);
console.log(namen);

