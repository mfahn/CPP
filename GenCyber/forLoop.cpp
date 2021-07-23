#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int count=0;
    cout<<count<<endl;
    //endl makes a new line

    for(count = 0; count < 10; count = count + 1 ){
        cout<<count;
    }

    cout<<endl;
    
    for(count = 10; count >= 0; count--){
        cout<<count<<endl;
    }

    return 0;
}