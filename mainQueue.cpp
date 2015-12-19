/*********************************************************
 ** Author: Carlos Carrillo                              *
 ** Date:   11/19/2015                                   *
 ** Description: Main driver program for Queue class     *
 ** Input: none.                                         *
 ** Output: Text based output demonstrating operation of *
 **         a Queue                                      *
 ********************************************************/

#include <cctype>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Queue.hpp"

using namespace std;

int intValid(); // input validation function prototype for int type

int main()
{
    int numValues;
    int actualValue;
    int choice;
    
    Queue myQueue;
    
    cout <<"\n\n*** WELCOME TO THE PROGRAM ***"<<endl;
    
    do{
        do{
            //main menu
            cout<<"\n**PLEASE SELECT ONE OF THE NEXT OPTIONS**\n"<<endl;
            cout<< "Enter 1 to INSERT values in the Queue List." <<endl;
            cout<< "Enter 2 to DISPLAY the Queue List contents." <<endl;
            cout<< "Enter 3 to REMOVE values from the Queue List." <<endl;
            cout<< "Enter 4 to SEE the value at the FRONT of the Queue List." <<endl;
            cout<< "Enter 5 to EXIT the program." <<endl;
            
            //Prompt the user to enter an option from the menu
            cout << "\nPlease enter your option: ";
            choice = intValid(); //take the input value
            cout <<endl;
            
            if(choice == 1) //insert values in the Queue List{
                //Prompt the user to enter the number of fighter for each lineup.
                cout<<"HOW MANY VALUES WOULD YOU LIKE TO INSERT? (0 = NULL): ";
                numValues = intValid();
                
                for(int i=0; i<numValues; i++){
                    //Prompt the user to enter a value
                    cout << "Please Enter a Value: ";
                    actualValue = intValid(); //take the input value
                    myQueue.addBack(actualValue);}}
            
            else if(choice == 2){ //display the queue contents
                myQueue.display();
                cout <<endl;}
            
            else if(choice == 3){//remove values from the Queue ListList
                //Prompt the user to enter the number of fighter for each lineup.
                cout<<"HOW MANY VALUES WOULD YOU LIKE TO REMOVE?: ";
                numValues = intValid();
                
                for(int i=0; i<numValues; i++){
                    //Prompt the user to enter a value
                    myQueue.removeFront();}}
            
            else if(choice == 4){ //see the value at the FRONT of the Queue
                int sentinel;
                sentinel = myQueue.getFront();
                cout<<"Sentinel to indicate an empty node: "<<sentinel<<endl;}
            
            else if(choice == 5){//EXIT the program
                return 0;}
            
        }while(choice != 1 && choice != 2 && choice != 3 && choice != 4);
        
        system("sleep 0.5");
   
    }while(choice);
    
    return 0;
}


//input validation function for an integer (borrowed from TA Ian)

int intValid(){
    int input;
    std::cin >> input;
    
    while (true){ //loops until the right input comes
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(512, '\n');
            std::cout <<"Invalid option entered. Try again!\n";
            std::cin >> input;}
        else break;
    }
    return input;
}



