#ifndef graph_h
#define graph_h
struct vertex;
struct arc;
#include <iostream>
#include <fstream>
using namespace std;
//have to initialize the structs so the compiler knows the 2 data types

struct vertex{
    char name;
    struct vertex* next;
    arc* arcHead; //head ofthe arclinked list
    bool processed; //true if added to queue or stack during traversal
};
struct arc{
    vertex* dest;
    struct arc*next;
};
void addVertex(vertex*& verHead, char n){
    vertex* newVertex = new vertex;
    newVertex->name = n;
    newVertex->next=nullptr;
    newVertex->arcHead=nullptr;
    newVertex->processed=false;
    if(verHead==nullptr){
        verHead=newVertex;
        return;
    }
    else if (newVertex->name < verHead->name){
        newVertex->next=verHead;
        verHead=newVertex;
        return;
    }
    else if (verHead->next == nullptr){
        verHead->next=newVertex;
        return;
    }
    else{
        vertex* temp=verHead;
        while(temp->next!=nullptr && newVertex->name > temp->next->name){
            temp=temp->next;
        }
        newVertex->next=temp->next;
        temp->next=newVertex;
    }
}
/*void push(vertex*& sHead, vertex*v){
    v->sNext=sHead;
    sHead=v;
    v->processed=true;
}*/
void pop(){

}
void depthTraversal(vertex* verHead){
    vertex* sHead=nullptr;
    
}
void printGraph(vertex* verHead){
    vertex* temp=verHead;
    arc* aTemp;
    while(temp!=nullptr){
        cout<<temp->name;
        //now print out arcs for Vertex
        aTemp=temp->arcHead;
        while(aTemp!=nullptr){
            cout<<"->"<<aTemp->dest->name;
            aTemp=aTemp->next;
        }
        cout<<endl;
        temp=temp->next;
    }
}
void addArc(vertex*verHead, char start, char end){
    arc* newArc = new arc;
    newArc->next = nullptr;

    vertex* startVer=nullptr;
    vertex* endVer=nullptr;
    vertex* temp = verHead;

    //need to find the memory address-matching
    while(temp!=nullptr){
        if(start==temp->name){
            startVer=temp;
        }
        else if(end == temp->name){
            endVer=temp;
        }
        temp=temp->next;
    }
    newArc->dest=endVer;

    //start and end vertexes have been found
    //insert newarc into startver arc linked list
    //start the paste
    //chec if graph is currently empty
    //insert newarc into start arc linked list

    if(startVer->arcHead == nullptr){
        startVer->arcHead = newArc;
        //verHead=newVertex;
        return;
    }
    else if (newArc->dest->name < startVer->arcHead->dest->name){
        newArc->next = startVer->arcHead;
        startVer->arcHead = newArc;
        return;
    }
    else if(startVer->arcHead->next == nullptr){
        startVer->arcHead->next = newArc;
        return;
    }
    else{
        arc* temp = startVer->arcHead;
        while(temp->next!=nullptr && temp->next->dest->name < end){
            temp=temp->next;
        }
        newArc->next = temp->next;
        temp->next = newArc;
    }
}
void remArc(vertex* verHead, char start, char end)
{
	// Traverse to find the starting vertex pointer
	vertex* vTemp = verHead;
	while(vTemp != nullptr && vTemp->name < start)
		vTemp = vTemp->next;
	if(vTemp == nullptr || vTemp->name != start){
		cout << "Could not find starting Vertex.\n";
		return;
	}else{
		// Starting vertex found, now look for arc to delete
		arc* dltPtr = vTemp->arcHead;
		if(dltPtr == nullptr){
			cout << "Arc is not found.\n";
			return;
		}else{
			// First scenario, check if delete the head
			if(dltPtr->dest->name == end){
				vTemp->arcHead = vTemp->arcHead->next;
				delete dltPtr;
				return;
			}
			// Second scenario, travere to node to delete
			// We need to stop one short of it
			arc* aTemp = vTemp->arcHead;
			while(aTemp->next != nullptr && aTemp->next->dest->name < end)
				aTemp = aTemp->next;
			if(aTemp->next == nullptr || aTemp->next->dest->name != end){
				cout << "Destination Vertex not found\n";
				return;
			}else{
				arc* delPtr = aTemp->next;
				aTemp = delPtr->next;
				delete delPtr;
			}
		}
	}
}
void findVert(vertex* verHead, char find){
    vertex* temp=verHead;
    while(temp->name != find){
        temp=temp->next;
    }
    cout<<"Vertex found "<< temp->name<< endl;
    return;
}
void remVertex(vertex*& vHead, char label){
    vertex* temp=vHead;
    vertex* forarc=vHead;
    vertex* onebefore = vHead;
    if(vHead->name == label){
        temp=vHead;
        vHead=vHead->next;
    }
    while(onebefore -> next != nullptr && onebefore->next->name != label ){
        onebefore=onebefore->next;
    }
    if(onebefore == nullptr)
        return;
    temp = onebefore -> next;
    arc* tarc;
    while(forarc != nullptr){
        tarc = forarc->arcHead;
        if(tarc != nullptr){
            if(tarc->dest->name == label){
                remArc(forarc, tarc->dest->name, label);
            }
            else if(forarc->name == label){
                remArc(forarc, label, tarc->dest->name);
            }
        }
        forarc=forarc->next;
    }
    onebefore->next=onebefore->next->next;
    delete temp;
    return;
}
#endif