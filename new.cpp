#include <iostream> // replaces <stdio.h>
using std::cout;
using std::cin;
//using namespace;
/* int main(){
    int x;
    //other code
    cout << myNamespace::x; //:: means find the varable after it in
     //std::cout << myNameSpace::x;                            //in the function to the left of it
    return 0;
}

#include <iostream>
using std::cout;
using std::cin;*/
int main(){
    int x, y;
    char c;
    cout<<"Insert a value for x: ";
    //cin>>x;
    cout<<"please enter 2 integers and a character: ";
    cin>>x>>y>>c;
    cout <<"x is equal to "<<x<<", and c is "<<c<<'\n';
    //"\n" works 
    //endl also ends string
}