#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
Brock Polnik
March 30 2023
3601365
TMA1Question2.cpp
*/

/*
Expectations: Write a program that takes in lines from a file one by one and prints to screen. Each line must get some user input after before the next line is taken inm.

This program simply opens a file and reads in the input one line at a time. The program expects the use to enter a 'y' and enter as input to continue, otherwise any other key should exit the program.
Entering more than one y when prompted will close the program ie)yy
Entering a capital "Y" is also acceptable. 
Empty lines are skipped.

This is a pretty simply program so I am not sure the exact limitations here.


*/


static void getInputFromFile(string filepath){

	

	if(filepath.length() <= 0){
		cout << "Empty file string. Shutting down";
		return;
	}	

	ifstream in(filepath);//Open file
	string input = "";//file input
	string userInput = "";//UserInput

	while (getline(in,input)){//Loop will lines left in program
		if(input.length() > 0){//If blank line then skip
    			cout << input + "\n";
    			cout << "Would you like to continue? Enter 'y' to continue enter any other key to exit: ";
    			cin >> userInput; 
			
    			if (userInput == "y" || userInput == "Y"){
        			//Continue
    		        }else{
        			cout << "Shutting down";
        			return;
    			}
    		}

	}

}

int main(){

//For the sake of each testing comment out the function call, otherwise there is you may be pressing 'y'+enter alot
//These are the same textfiles from question 1

//Testcase1, Random words, Now empty lines
cout << "File: " << "Q1Testcase1.txt";
getInputFromFile("Q1Testcase1.txt");

//Testcase2. Paragraphs,Empty lines
cout << "File: " << "Q1Testcase2.txt";
getInputFromFile("Q1Testcase2.txt");

//Testcase3. Random words and symbols, single line
cout << "File: " << "Q1Testcase3.txt";
getInputFromFile("Q1Testcase3.txt");


//Testcase4. Random words and symbols. Sporatic spacing, paragraphs
cout << "File: " << "Q1Testcase4.txt";
getInputFromFile("Q1Testcase4.txt");

//Testcase5,Entire bee movie script
cout << "File: " << "Q1Testcase5.txt";
getInputFromFile("Q1Testcase5.txt");
}
