#include "random.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    
    int x = rand () % 100;
    //x has a random number between 0 and 99
    cout<<x<<endl;

    //try this first
/*    while(x != 47){
        x= rand() % 100;
        cout<<x<<endl;
    }*/

    //But that ^ is too easy. Let's learn about functions!
//do/while loops are just like while loops but the condition is checked
//at the bottom instead of the top
    int Catch;
    do{
         Catch = get_number();
        //^ the variable Catch gets the number that the get_number function sends back
        print_number(Catch);
        //here we send Catch to he print_number function to be printed out
        Sleep(100);
        //This tells the computer to slow down for 100 milliseconds
    }while(Catch != 100);
    //if Catch is 100 then it exits the loop

    return 0;
}