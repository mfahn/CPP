//All of the data structures are here.
#include <iostream>
using namespace std;

struct players{
    players *next;
    string name;

    int health;
    int damage;
    
};
struct enemies{
    enemies *next;
    string name;
    int health;
    int damage;

};