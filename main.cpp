#include "ll.h"
#include <iostream>
using namespace std;

int main(){
    node* head=nullptr;

    insertNode(head, 1, 0);
    printlist(head);
    insertNode(head, 2, 0);
    printlist(head);
    insertNode(head, 3, 0);
    printlist(head);
    insertNode(head, 2, 0);
    printlist(head);

    //insert at end
    insertNode(head, 3,3);
    printlist(head);

    //insert at middle
    insertNode(head, 3,3);
    printlist(head);

        //insert at head
    insertNode(head, 3,3);
    printlist(head);

    //delete
    deletenode(head, 0);
    printlist(head);
    deletenode(head, 3);
    printlist(head);
    deletenode(head, 0);
    printlist(head);
    deletenode(head, 1);
    printlist(head);
    deletenode(head, 0);
    printlist(head);
    deletenode(head, 7);
    printlist(head);
    return 0;
}