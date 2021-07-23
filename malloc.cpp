#include <iostream>
#include <cstdlib>

using namespace std;
void PBRExample(int& x){
    x=10;
}
int main(){
    int y=0;
    PBRExample(y);
    cout<<"In main y is "<<y<<endl;
    return 0;
}
/*
int* arr=(int*)malloc(sizeof(int)*10);
arr[0]=5; arrays dereference
10= *arr + 3;
*/

/*int* myptr;using namespace std;
myptr=(int*)malloc(sizeof(int));

int* array=new int[10];
delete [] array;

int* myptr= new int;
delete myptr;*/