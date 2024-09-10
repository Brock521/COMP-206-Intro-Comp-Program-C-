//Array of 100 strings,tesxst file, use line numbers
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

#define BUFFERSIZE 100//Max number of lines that can be handled
/*
Brock Polnik
March 30 2023
3601365
TMA1Question4.cpp
*/

/*
Expectation: Read 100 lines of strings from a file and insert into an array. Output to screen using format "Line" # then the string

This program uses a filestream to get lines from a file one by one. It will enter in up to BUFFERSIZE number of strings. If the file has to many lines the reamaining lines are ignored


We then loop through the filled array and print it in the format by printing "Line" << (indice+1) << arr(indice)

*/


static void fillAndPrintStringArray(string fileName){

	string buffer[BUFFERSIZE];//Arr that holds the strings
	fstream fileIn(fileName);//Open file stream
	string currLine = "";
	int actualSize = 0;//This is the number of actual strings retrieved from the file

	while(getline(fileIn,currLine) && actualSize<BUFFERSIZE){
		buffer[actualSize] = currLine;
		actualSize++;
		
	}
	
	if(actualSize <= 0){
		cout << "The file was empty shutting down\n";
		return;
	}


	for(int indice = 0; indice < actualSize; indice++){
    		cout << "Line " << (indice+1) << ":" << buffer[indice] << "\n";
	}
}



int main(){

//Testcase1, Random words, Now empty lines
cout << "File: " << "Q1Testcase1.txt";
fillAndPrintStringArray("Q1Testcase1.txt");
cout << "\n";

//Testcase2. Paragraphs,Empty lines
cout << "File: " << "Q1Testcase2.txt";
fillAndPrintStringArray("Q1Testcase2.txt");
cout << "\n";

//Testcase3. Random words and symbols, single line
cout << "File: " << "Q1Testcase3.txt";
fillAndPrintStringArray("Q1Testcase3.txt");
cout << "\n";

//Testcase4. Random words and symbols. Sporatic spacing, paragraphs
cout << "File: " << "Q1Testcase4.txt";
fillAndPrintStringArray("Q1Testcase4.txt");
cout << "\n";

//Testcase5,Entire bee movie script
cout << "File: " << "Q1Testcase5.txt";
fillAndPrintStringArray("Q1Testcase5.txt");
cout << "\n";

return 0;

}
