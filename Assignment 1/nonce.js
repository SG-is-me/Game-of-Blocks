
const SHA256= require('crypto-js/sha256');
const read = require('readline-sync');
const performance = require('perf_hooks');
let string= read.question ("Enter the string\n");

const TARGET= '00000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF' ;

let current=1 ;
let new_string=string+current ;
// const start = performance.now();
    console.time("exec time");

for (current=1;  ;current++){
    new_string=string+current ;
    if (SHA256(new_string).toString()<TARGET){
              break;
    }
}
// const end = performance.now();
    // console.log(`Execution time: ${end - start} ms`);
    console.timeEnd("exec time");

console.log(current);
console.log(SHA256(new_string).toString());