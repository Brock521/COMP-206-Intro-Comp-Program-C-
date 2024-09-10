//2 nested for loops
//% to print prime numbers
//1-10000
#include <string.h>
#include <stdlib.h>
#include <iostream>

/*
Brock Polnik
March 30 2023
3601365
TMA1Question4.cpp
*/


//This is the debug file for Q3. Each number as they are iterated through and if the number is prime.


#define MAX 10000

using namespace std;

static void printPrimes(){

bool isPrime = true;

for(int i = 2; i < MAX; i++){
	cout << "Current number=" << i << "\n";
    for(int y = 2; y <= 9; y++){
        // if i% y == 0 then not prime
        if (i% y == 0 and i !=y){
            isPrime = false;
            cout << "Non Prime Number Detected:" << i << "Is prime = " << isPrime << "\n";
        }

    }

    if(isPrime){
        cout << "Prime found "  << i << "\n ";
    }
    isPrime = true;
}




}

int main(){

printPrimes();

return 0;

}
