#include <iostream>
#include "graph.h"
using namespace std;

int main(){
    int n, x;
    char name;
    vertex* verHead=nullptr;

    cout<<"How many new vertices: ";
    cin>>n;
    for(x=1; x<=n; x++){
        cout<<"Enter a letter: ";
        cin>>name;
        addVertex(verHead, name);
        printGraph(verHead);
        cout<<endl;
    }

	addArc(verHead, 'A', 'D');
	addArc(verHead, 'B', 'C');
	addArc(verHead, 'B', 'A');
	addArc(verHead, 'A', 'B');
	addArc(verHead, 'C', 'B');
	addArc(verHead, 'C', 'A');
	addArc(verHead, 'C', 'D');
	addArc(verHead, 'C', 'E');
    printGraph(verHead);
    cout<<endl;

    remVertex(verHead, 'B');
    printGraph(verHead);
    cout<<endl;

    return 0;
}