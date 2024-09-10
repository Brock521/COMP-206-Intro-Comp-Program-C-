/*
Brock Polnik
March 30 2023
3601365
TMA2Question3.cpp
*/

/*
This is essentially part 2 of trying to test the speed difference between non-inline and inline functions

This file holds the inline function

During testing these were the following times
t1.74740
t2.90940
t3.76240
t4.84893
t5.90131

avg time = 83388

//In-line functions are suppossed to be faster however from testing they seem to be about the same atleast for this file


*/
#include <ctime>
#include <iostream>

using namespace std;

//Get current time method
//Mulitply method
//Create an array * 2

inline void multiplyArrays(){
    
    double arr1[10000];
    double arr2[10000];
   

    for(int x = 0; x < 10000; x++){
        arr1[x] = x+100;
        arr2[x] = 10100-x;


    }

    for(int x = 0; x< 10000; x++){
        cout <<  (arr1[x] * arr2[x]) << "\n";
    }

}


int main(){
   
    for(int i = 0; i < 5; i ++){
    cout << "Test:" << i+1 << "\n";
    time_t startTime = clock();
    //function call
    multiplyArrays();
    time_t endTime = clock();
    time_t ellapsedTime = difftime(endTime,startTime);
    cout << "Total ellapsed :" << ellapsedTime << "\n";
 
 }   
}
