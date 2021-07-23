#include "heap.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int heap[1000], n, key;
    int size=0;
    cout<<"Enter the number to insert: ";
    cin>>n;
    for(int x=0; x<n; x++){
        cout<<"Please enter a new value: ";
        cin>>key;
        insertNode(heap,size, key);
        printHeap(heap, size);
    }
    int result=deleteNode(heap, size);
    cout<<"Result is "<<result<<endl;
    printHeap(heap, size);
    return 0;
}