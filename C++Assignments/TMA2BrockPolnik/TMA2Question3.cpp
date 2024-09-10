/*
Brock Polnik
March 30 2023
3601365
TMA2Question3.cpp
*/


/*
Expectation: Write a class with 2 constructors a default and a single string argument that is the name of the file to open. Write a function contents() that displays all info in the file;

	_____________________	
	|	Text        |	
	|___________________|
	|Fields:	    |
	| stringinput	    |
	|		    |
	|Functions: 	    |
	| Text()	    |
	| Text(fileName)    |
	| contents()        |//Void member function
	|___________________|
	
*/

#include <string>
#include <fstream>
#include <iostream>

using namespace std;




class Text{
 public:
    //Member Fields
    string fileInput;
    //Member functions
    Text() : fileInput(""){}
    Text(string);
    void contents();

};

Text::Text(string fileName){

     fileInput = "";

    
    if(fileName.length() <= 0){
        cout << "FileName was not found \n";
    }else{
        cout << "FileName was found:" << fileName << "\n";
        ifstream in(fileName);
        cout << "FileStream Opened";
        
        string currLineInfo = "";
        while(getline(in,currLineInfo)){
            fileInput += currLineInfo;
        }
        
        in.close();

    }

  
}

void Text::contents(){
    
    if(fileInput.length() <= 0){
        cout << "String in empty" << "\n";
    }else{
        cout << fileInput << "\n";
    }

}

int main(){
    
    string testCaseNum[] = {"DVDFile1.txt","DVDFile2.txt","DVDFile3.txt","DVDFile4.txt","DVDFile5.txt"};
   
   for(int tc = 0; tc < 5; tc++){
   	cout << "Testcase:" << (tc+1) << "\n";
   	Text test(testCaseNum[tc]);
    	test.contents();
    }
    return 0;
}
