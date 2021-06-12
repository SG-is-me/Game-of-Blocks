# SMART CONTRACT

A smart contract which acts as a loan deposit and settling contract.<br>
There are two contracts:<br>
### Contract MetaCoin
 Implements a basic token which the accounts can give to each other with the ` sendCoin ` function, and see their balance with the ` getBalance ` function

### Contract Loan
There is be an Owner of the Loan contract, and he has an initial balane of 100K MetaCoins. He has accumulated these 100K coins by taking loans. It contains many functions:<br>
1. ` getCompoundInterest `: ANYONE can use it to calculate the amount of interest for given values of P, R, T.
2. ` reqLoan `: ANYONE can use it to request the Owner to settle his loan.
3. ` getOwnerBalance `: ANYONE can use it to get the amount of MetaCoins owned by the owner.
4. ` viewDues ` : ONLY THE OWNER can access this to view the amount of loan he owes to the input address.
5. ` settleDues `: ONLY THE OWNER can use this to settle the amount of loan he owes to the input address.

### HOW TO USE
* Open the metacoin.sol, copy the code, then run it on [REMIX](https://remix.ethereum.org)
* Compile the code
* From the left side bar, choose any one of the 10 test cases already given in REMIX and Deploy the smart contract.

### To request the owner to pay back the loan
* From the many test cases, select any one (other than the owner of course), type in the P,R,T in reqLoan
* Click on transact
### To view and settle the dues
* Since only the owner can do these, select the address of the Owner
* Type in the address of the lender in the suitable box and call the function
### Any other function
* Just type in the necessary arguments and call the functions

#### EXAMPLE
Let the address of the Owner as `0x5B38Da6a701c568545dCfcB03FcB875f56beddC4` and the address of the creditor as `0xAb8483F64d9C6d1EcF9b849Ae677dD3315835cb2`<br>
When we deploy the contract, the Owner's initial balance is given as 100k.<br>
Then changing the address to that of the creditor and then using the reqLoan function requests the Owner to pay the due amount to the creditor.<br>
To view and settle the dues, go back to the original address(of the Owner), call the viewDues and the settleDues function (after typing in the address of the creditor of course).<br>



> EXTRA INFO
> QUES. Why are some functions view and others pure?
> ANS. The view functions are read-only function, which ensures that state variables cannot be modified after calling them. The pure functions returns the values only using the parameters passed to the function.<br>
> A common way to perform division to calculate such percentages is mentioned here as references:
>   [COMPOUND INTEREST](https://medium.com/coinmonks/math-in-solidity-part-4-compound-interest-512d9e13041b)
>   [PERCENTS AND PROPORTIONS](https://medium.com/coinmonks/Math-in-solidity-part-3-percents-and-proportions-4db014e080b1)