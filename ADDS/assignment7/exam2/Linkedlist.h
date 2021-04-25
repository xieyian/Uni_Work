#ifndef _Linkedlist_H
#define _Linkedlist_H
#include "Node.h"
#include <vector>

class Linkedlist{
private:
    Node* head;
    int length;
    Node* pointer;

public:
    Linkedlist();
    Linkedlist(std::vector <int> input);
    void removeDupes(); // removes all duplicate entries in linked list.
    Node* findmin();
    void swap(int n);
    void printItems();
    void deletePosition(int position);
   
    void addFront(int newItem);
    void addEnd(int newItem);
    void addAtPosition(int position, int newItem);
    int search(int item);
    void deleteFront();
    void deleteEnd();
    
    ~Linkedlist();





};
#endif
