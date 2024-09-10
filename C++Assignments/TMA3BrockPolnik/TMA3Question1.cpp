/*
Brock Polnik
March 30 2023
3601365
TMA2Question3.cpp
*/

/*
This is essentially part 1 of trying to test the speed difference between non-inline and inline functions

This file holds the non-inline function

During testing these were the following times
t1.62664
t2.71301
t3.94613
t4.75642
t5.78773

avg time = 76598


*/


#include <ctime>
#include <iostream>

using namespace std;

//Get current time method
//Mulitply method
//Create an array * 2

void multiplyArrays(){
    
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
