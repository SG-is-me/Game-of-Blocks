
const SHA256= require('crypto-js/sha256');
const read = require('readline-sync');
const performance = require('perf_hooks');
let string= read.question ("Enter the string\n");

const TARGET= '00000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF' ;

let current=1 ;
let new_string=string+current ;
    console.time("exec time");

for (current=1;  ;current++){
    new_string=string+current ;
    if (SHA256(new_string).toString()<TARGET){
              break;
    }
}
console.timeEnd("exec time");
console.log("The nonce value is: ")
console.log(current);
console.log("The hash of the new string is: ")
console.log(SHA256(new_string).toString());