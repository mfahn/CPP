#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int y= 2, x = 4;
        // V <-put the number of array spots here
    string array[] = {{"4/2 (division) is "}, {"4%2 (modulo) is "}};

    int number = x/y;
    cout<< array[0]<<number<<endl;

    number = x % y;   
    cout<<array[1]<<number<<endl;
    
    return 0;
}