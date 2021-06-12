// SPDX-License-Identifier: MIT
pragma solidity >=0.4.25 <0.7.0;

// This is just a simple example of a coin-like contract.
// It is not standards compatible and cannot be expected to talk to other
// coin/token contracts. 

contract MetaCoin {
	mapping (address => uint256) balances;

	event Transfer(address indexed _from, address indexed _to, uint256 _value);

	constructor() public {
		balances[tx.origin] = 100000;
	}

	function sendCoin(address receiver, uint256 amount, address sender) public returns(bool sufficient) {
		if (balances[sender] < amount) return false;
		balances[sender] -= amount;
		balances[receiver] += amount;
		emit Transfer(sender, receiver, amount);
		return true;
	}


	function getBalance(address addr) public view returns(uint256) {
		return balances[addr];
	}
}


contract Loan is MetaCoin {

    mapping (address => uint256) private loans;
     
    event Request(address indexed _from, uint256 P, uint256 R, uint256 T, uint256 amt);
    
    address private Owner=msg.sender;
    
    constructor() public {
        Owner = msg.sender;    //The creator of the contract is the owner.
    }
    
    modifier isOwner() {
        require(msg.sender == Owner,"Caller is not owner");   //Only the owner of the contract can use specific functions
        _;
    }   
    
    function mulDiv (uint256 x, uint256 y, uint256 z) internal pure returns (uint256) {
        return (x * y) / z;
    }
    
    function add(uint256 a,uint256 b) internal pure returns(uint256)
    {
        return a+b;
    }
    
    function getCompoundInterest(uint256 principal, uint256 rate, uint256 time) public pure returns(uint256) {
        
        for(uint i=time; i>0;i--)
            principal = add (principal, mulDiv (rate, principal, 10^18));
        return principal;
        //Anyone can use this function to calculate the amount of Compound interest for given P, R, T
        
        
    }
    
    function reqLoan(uint256 principle, uint256 rate, uint256 time) public returns(bool correct) {
        uint256 toPay = getCompoundInterest(principle, rate, time);
        if (toPay < principal)
            return false;
        if (msg.sender == Owner) 
            return false;
            
        loans[msg.sender] = toPay;
        emit Request(msg.sender,principle,rate,time,toPay);
        return true;
        // A creditor uses this function to request the Owner to settle his loan, and the amount to settle is calculated using the inputs.
        // Store the loan request of a contract in the loans mapping,
        // Emits the Request event after succesfully adding to the mapping, and return true. Return false if adding to the mapping failed (maybe the user entered a float rate, there were overflows and toPay comes to be lesser than principle, etc.
    }
    
    function getOwnerBalance() public view returns(uint256) {
            uint256 bal;
            bal = MetaCoin.getBalance(Owner);
            return bal;
				// use the getBalance function of MetaCoin contract to view the Balance of the contract Owner.
	}

    function viewDues(address creditor) public view isOwner returns(uint256) {
        uint256 dues = loans[creditor];
        return dues;
    }
    
    // The following two functions can only be accessed by the OWNER to settle and view his loans respectively.
    // They take in the address of a creditor as arguments. 
    // viewDues returns a uint256 corresponding to the due amount, and does not modify any state variables. 
    // settleDues returns a bool, true if the dues were settled and false otherwise. 
    // Use sendCoin function of MetaCoin contract to send the coins required for settling the dues.

    function settleDues(address creditor) public isOwner returns(bool){
        if(loans[creditor]<=getOwnerBalance())
        {
            MetaCoin.sendCoin(creditor,loans[creditor],Owner);
            loans[creditor]=0;
            return true;
        }
        else
        {
            MetaCoin.sendCoin(creditor,getOwnerBalance(),Owner);
            loans[creditor]=loans[creditor] -getOwnerBalance();
        }
        return false;
    } 
    
}