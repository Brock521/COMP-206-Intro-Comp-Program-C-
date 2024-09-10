//2 nested for loops
//% to print prime numbers
//1-10000
#include <string.h>
#include <stdlib.h>
#include <iostream>

#define MAX 10000//Look for primes up to this value

using namespace std;

/*
Brock Polnik
March 30 2023
3601365
TMA1Question3.cpp
*/

/*
Expectations: List all prime values between 1 and 10000 by using the mod function (%)
The this program has a outer loop that counts from 1 to 10000 and a inner loop that loops from 2 to 9;
We use the value of the outter loop and mod it by the inner loop. If the remainder is 0 then it is not prime ie) the inner loops value is a factor of the outter loops value.


*/
static void printPrimes(){

	bool isPrime = true;

	for(int target = 2; target < MAX; target++){
	    for(int  div = 2; div <= 9; div++){
	        // if target% div == 0 then not prime
	        if (target%div == 0 and target !=div){
	            isPrime = false;
	        }
	
	    }
	    	if(isPrime){
	    	    cout << target << ", ";
	    	}
    
	    	isPrime = true;
	}

}

int main(){

printPrimes();

return 0;

}
