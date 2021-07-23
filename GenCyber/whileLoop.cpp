#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int counter=0;
    cout<<counter<<endl;

    while(counter < 10){
        cout<<counter<<" ";
        counter++;
    }
    //what will counter be at the end of this loop?

    cout<<endl;
    
    while(counter != 0){
        cout<< counter <<" ";
        //spacing in cout does not matter
        //if you want space between numbers add <<" " at the end
        counter--;
    }
    //what will counter be at the end of this loop?

    return 0;
}