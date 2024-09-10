/*
Brock Polnik
March 30 2023
3601365
TMA2Question3.cpp
*/

/*
Goal: Write a program class Hen,with a nested nest class,with a egg class nested in nest.
	      Create a constructor and destructor that prints and appropriate message, and  a function display for each class.
	Requirements:Write a constructor,Destructor and display for each class. Objects calls are done in main();
	
	____________________		___________________		_____________________
	|	Hen	   |		|	Nest	  |		|	Egg	    |
	|__________________|		|_________________|   		|___________________|
	|Class:    	   |	        |Class:		  |		|Functions:	    |
	| Nest		   |		| Egg		  |		| Egg()             |
	| 		   |		|Functions:	  |		| ~Egg()            |
	|Functions:        |  		| Nest()	  |		|  Display()	    |
	| Hen()		   |		| ~Nest()	  |		|___________________|
	| ~Hen()	   |		| Display()       |
	| Display()	   |		|_________________|
	|__________________|
*/	


#include <iostream>

using namespace std;

class Hen{
 public:
    //Member functions Hen
    Hen();
    ~Hen();
    void display();

    class Nest{
     public:
        //Member Functions Nest
        Nest();
        ~Nest();
        void display();

        class Egg{
        //Member functions Egg
         public:
             Egg();
             ~Egg();
             void display();
   

        };
    };
};


    Hen::Hen(){
        cout<< "I am a Hen! Hello.";
    }

    Hen::~Hen(){
         cout<< "I am a Hen! I am being destroyed. GoodBye";
    }

    void Hen::display(){
        cout << "I am a Hen!";
         
    }

    Hen::Nest::Nest(){
            cout<< "I am a Nest! Hello.";
        }

    Hen::Nest::~Nest(){
        cout<< "I am a Nest! I am being destroyed. GoodBye\n";
    }

    void Hen::Nest::display(){
        cout << "I am a Nest!";
    }  


     Hen::Nest::Egg::Egg(){
        cout<< "I am an Egg! Hello.";
    }

    Hen::Nest::Egg::~Egg(){
        cout<< "I am an Egg! I am being destroyed. GoodBye";
    }

    void Hen::Nest::Egg::display(){
        cout << "I am an Egg!";
    }  




int main(){
    Hen *hen = new Hen();
    Hen::Nest *nest = new Hen::Nest;
    Hen::Nest::Egg *egg = new Hen::Nest::Egg;
    
    cout << "\n";
   
    hen->display();
    nest->display();
    egg->display();
   
    cout << "\n";

    delete egg;
    delete nest;
    delete hen;
    

}
