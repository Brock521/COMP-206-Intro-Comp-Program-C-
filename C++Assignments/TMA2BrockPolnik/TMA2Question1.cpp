/*
Brock Polnik
March 30 2023
3601365
TMA2Question3.cpp
*/


/*

	Goal: Write a program to manage a DVD rental store
	Requirements: Make a DVD type. DVD type must contain required DVD info and be	
		      read out from and array of DVD type objects. 

These are some fields and functions I thought would be benefical to a simple DVD store database	
	____________________	____________________________
	|	DVD	   |	|     Video Rental Store    |
	|_________________ |    |Fields			    |
	|Fields            |    | Dvd[]                     |
	|  Condition Case  |    | totalStock                |
        |  Condition CD    |    |Functions                  |
	|  Movie Title     |    | getNumberOfCopies(DVD)    |
 	|  Maturity Rating |	| getTotalStock()	    |
	|                  |	| inStock(DVD)	            |
	|__________________|    | rent(DVD)                 |
				| return(DVD)               |
				|___________________________|
				
				


DVD info is read from the file in the following format{
	Movie title
	Director
	Age rating
	Case condition
	Disk condition}These are all fields required for a DVD object
In file there must be no empty lines to be read in

All of these fields are strings so technically anything can be entered and and they dont need to make any sens, there is no handling to account for random symbols and non-sensical words
however the movie title field is essentially its id so if we want to add,remove, or modify a DVD we need movie titles that we can easily search for.

We created a class Video rental store to handle the "stock" of DVD objects
Stock is limited by the stock capacity

By creating a Video rental store class we have the opporunity to create a more robust stock database in the case we want to sell merch, snacks, or whatever else you may buy 
we would just need to generalise the code a bit 



*/

#include <string>
#include <iostream>
#include <fstream>

using namespace std;



class DVD{
    string movieTitle;
    string director;
    string maturityRating;//g,PG,PG-13,M,etc.
    string caseCondition;
    string diskCondition;

public:
    DVD(){
        movieTitle = "";
        director = "";
        maturityRating = "";
        caseCondition = "";
        diskCondition = "";
    }

    DVD(string mt, string d, string mr, string cc, string dc){
        movieTitle = mt;
        director = d;
        maturityRating = mr;
        caseCondition = cc;
        diskCondition = dc;

    }
    
    string getMovieTitle(){
        return movieTitle;
    }

    string getMovieDirector(){
        return director;
    }

    string getMaturityRating(){
        return maturityRating;
    }

    string getCaseCondition(){
        return caseCondition;
    }

    string getDiskCondition(){
        return diskCondition;
    }
    
    void printDVDInformation();
    
};

class VideoRentalStore{
    //private fields
    int totalStock = 0;
    const int stockCapacity = 10;
    DVD stock[10] = {};
   

public:
    
    DVD rentDVD(DVD);//Add to stock
    DVD returnDVD(DVD);//Remove from stock
    //Just for simpllicity these are just going to add or remove and item from 
    //the DVD array. Otherwise we could maybe make a stockItem class that contains
    //stock type and availiabilty as this is a rental business not store, the items could technically
    // be stocked but just rented out and expected to be returned at some point. So in this case if the DVD is not in the Dvd array 
    //we will have no information about it

    int getNumberOfCopies(DVD);
    int getTotalStock();
    bool inStockByTitle(DVD);

    VideoRentalStore(){
        //init with dummy dvd's
        totalStock = 0;
        for(int i = 0; i<stockCapacity; i++){
            stock[i] = (DVD("","","","",""));
        }

    }

};



int VideoRentalStore::getNumberOfCopies(DVD item){

int numberOfCopies = 0;

for(int index =0; index < totalStock; index++){
    if(stock[index].getMovieTitle() == item.getMovieTitle() ){
        numberOfCopies++;
    }

}

return numberOfCopies;

}

int VideoRentalStore::getTotalStock(){
//We will print each item and return the total number of items in stock

for(int index = 0; index < totalStock; index++){
    stock[index].printDVDInformation();
}

return totalStock;
}

bool VideoRentalStore::inStockByTitle(DVD item){

return getNumberOfCopies(item) > 0;

}

 DVD VideoRentalStore::returnDVD(DVD item){

    if(totalStock >= stockCapacity){//Can not accept any more DVD's
        return item;
    }

    int index = 0;

    while(index < stockCapacity ){
        if(stock[index].getMovieTitle() == ""){
            stock[index] = item;
            totalStock++;
            return item;
        }
        index++;
    }

    //If we are here it means the the totalStock is below the capacity, yet there is no open spaces. This should no occur
    //However we will put a message just in case

    cout << "Could not find a storage location for this DVD. Please contact customer service\n";
    return item;


 }

 DVD VideoRentalStore::rentDVD(DVD item){
       
       if(totalStock <= 0){
        cout << "We currently have no stock. You can keep the DVD or Contact customer service\n"
             << "Rental denied! Item: ";
        return item;
    }

    int index = 0;

    while(index < stockCapacity ){
        if(stock[index].getMovieTitle() == item.getMovieTitle()){
            stock[index] = DVD("","","","",0);
            totalStock--;
            return item;
        }
        index++;
    }

    return item;

 }

void DVD::printDVDInformation(){

cout << "\n"
     << "===================================" << "\n"
     << "Movie title: " << getMovieTitle() << "\n"
     << "Director: " << getMovieDirector() << "\n"
     << "Maturity Rating: " << getMaturityRating() << "\n"
     << "Case Condition: " << getCaseCondition() << "\n"
     << "Disk Condition: " << getDiskCondition() << "\n";

}


int main(){

    VideoRentalStore test;

     //Get input from file and create dvd objects
    
    string title;
    string director;
    string maturityRating;
    string caseCondition;
    string diskCondition;
    int itemCount = 0;
    string testCaseNum[] = {"DVDFile1.txt","DVDFile2.txt","DVDFile3.txt","DVDFile4.txt","DVDFile5.txt"};
   
   for(int tc = 0; tc < 5; tc++){
   	cout << "Testcase:" << (tc+1);
   	VideoRentalStore test;
   	ifstream in(testCaseNum[tc]);
        while(!in.eof() && itemCount <=10){
        	getline(in,title);
        	getline(in,director);
        	getline(in,maturityRating);
        	getline(in,caseCondition);
        	getline(in,diskCondition);
        	test.returnDVD(DVD(title,director,maturityRating,caseCondition,diskCondition));
        	itemCount++;
    }
  	itemCount = 0;
  	test.getTotalStock();
  	cout << "\n";
  }


  

    return 0;
}
