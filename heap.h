#ifndef heap_h
#define heap_h
#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;

void reheapUp(int heap[], int size){
    int x=size-1;
    int parent = (x-1)/2;
    while( x!=0 && heap[x]>heap[parent]){
        //swap parent and child
        int temp=heap[x];
        heap[x]=heap[parent];
        heap[parent]=temp;
        x=parent;
        parent=(x-1)/2;
    }
}
void reheapDown(int heap[], int size){
    int x=0;
    int lc, rc, daddy;
    lc =2*x+1;
    rc =2*x+1;
    while(lc<size){
        if(rc<size){
            if(heap[rc]>heap[lc])
                daddy=rc;
            else
                daddy=lc;
        }
        else{
            daddy=lc;
        }
        if(heap[x]<heap[daddy]){
            int temp=heap[x];
            heap[x]=heap[daddy];
            heap[daddy]=temp;
        }
        else{
            return;
        }
        x=daddy;
        lc=2*x+1;
        rc=2*x+2;
    }
}
void insertNode(int heap[], int& size, int key){
    int x;
    heap[size]=key;
    size++;
    reheapUp(heap,size);
}
void printHeap(int heap[], int size){
    for(int x=0; x<size;x++){
        cout<<heap[x]<<"   ";
    }
    cout<<endl;
}
int deleteNode(int heap[], int& size){
    int output=heap[0];
    heap[0]=heap[size-1];
    size--;
    reheapDown(heap,size);
    return output;
}
#endif