#include <iostream>
#include <fstream>
#include <string>


using namespace std;


/*
Brock Polnik
March 30 2023
3601365
TMA1Question1.cpp
*/


/*
Expectations: The program should be able to open a file and count whitespace seperated words	
 
This program works by getting a line from a file, putting it into a string, then checks each index of the string
for single whitspaces(Whitespaces such that there is no whitespace before or after it). It takes count of single whitespaces and returns the 
number of single whitespaces + 1;This is the word count eg) This sentence has five words 
								^	 ^   ^    ^
								1    +   1 + 1  + 1 = (4 whitespaces + 1) = 5 Words
								
This program will trim beggininging and end whitespaces before counting whitespaces. And will check for blocks of whitespaces where whitespaces are back to back and ignore them;
This program will ignore empty lines

Limitations:
As this is a simple program this will be considered a sentence with 6 words  h o t d o g just as a b c d e f  or ! @ # $ % ^ is. This does not filter for real words, numbers or symbols. Essentially a word is a block of characters.
This program requires that all words come from some file and not individually enterered through terminal or creating strings. 


*/




void fillWhiteSpaceBlocks(string &line){
//This function is reponsible for filling in whitespace blocks


    //Test for empty strings
     if (line.length() == 0){
     	return;
     }

    //First we will look at the front of the string and fill in whtitespaces
    //Start at the fron and increment while chr(32)/space is present
    if(line[0] == char(32)){
        int index =0;
        while(line[index] == char(32) && index < line.length()){
            line[index] = char(95);
            index++;
        }
    }

    //Then we look at the end and count backwards
    if(line[line.length()-1] == char(32)){
        int index = line.length()-1;
        while(line[index] == char(32) && index >=0 ){
             //Chr(95) is just a placeholder this can be any number, letter, or symbol
            // this does not matter as only whitespace is important
            line[index] = char(95);           
            index--;
        }
     }
    //Now we look for places where there is multiple whitespaces and fill until
    //in whitespace blocks so that only and individual whitespace per block remains

    bool isWhiteSpace = false;//To signify is a whitespace was present in the index just before

    for(int index = 0; index < line.length(); index++){

        if(isWhiteSpace){//If previous position was whitespace and current position is then set placeholder
             if(line[index] == char(32)){
                line[index-1] = char(95);
            }
        }

        if(line[index] == char(32)){
                isWhiteSpace = true;
        } else{
                isWhiteSpace = false;

        }

    }
}

    
int countWords(string fileName){

	ifstream fileIn(fileName);
	string currLine = "";
	int wordCount = 0;
	int whitespaceCount = 0;

	while (getline(fileIn,currLine)){
		if (currLine.length() > 0){//Ignore empty lines
			fillWhiteSpaceBlocks(currLine);//Remove whitespace blocks first
		
			for(int i =0; i < currLine.length(); i++){//Loop through the string and count whitespaces
				if(currLine[i] == char(32)){
					whitespaceCount++;
				}
			}
			
			whitespaceCount++;
			wordCount += whitespaceCount;
			whitespaceCount = 0;
			currLine = "";
		}
	}
	
	whitespaceCount++;//Increment to account for the first word

	cout << "Exiting countWords(). \n" ;
	cout << "Total Number of words: " << wordCount << "\n";
	return wordCount;
	
	
}

int main(){

//Testcase 1 391 word count
string fileName("Q1Testcase1.txt");

cout << "FileName: " << fileName << "\n";
cout << " Testcase 1 391 word count\n ";  
countWords(fileName);
cout << "\n";

//Testcase 2 409 Word Count, Sentences, paragraphs
fileName = ("Q1TestCase2.txt");

cout << "FileName: " << fileName << "\n";
cout << "Testcase 2 409 Word Count, Sentences, paragraphs\n";
countWords(fileName);
cout << "\n";

//TestCase 3, Single line random words and symbols no spaces
fileName = ("Q1Testcase3.txt");


cout << "FileName: " << fileName << "\n";
cout << "TestCase 3 1 Word Count, Single line random words and symbols no spaces \n";
countWords(fileName);
cout << "\n";

//TestCase 4 37 Word Count, Random characters and symbols, paragraphs
fileName = ("Q1Testcase4.txt");

cout << "FileName: " << fileName << "\n";
cout << "TestCase 4 37 Word Count, Random characters and symbols, paragraphs \n";
countWords(fileName);
cout << "\n";

//TestCase 5, The entire bee movie script
fileName = ("Q1Testcase5.txt");
cout << "TestCase 5 9154 word count. Bee movie script \n";
cout << "FileName: " << fileName << "\n";
countWords(fileName);
}

