#ifndef _LinkedList_H
#define _LinkedList_H
#include <string>
#include "Node.h"

class LinkedList{
private:
    Node* head;
    Node* end;
    int length;


public:
LinkedList();
//A constructor that takes an array of integers and makes a linked list, containing all the elements of the array, in the same order. As the second parameter, it takes the size of the array.
LinkedList(int a[],int sizeofa);
//A destructor that manually deletes all the elements that are still in the list.
~LinkedList();
//The function inserts a new node, containing the newItem, at the beginning of the list.
void addFront(int newItem);
// The function inserts a new node, containing the newItem, at the end of the list.
void addEnd(int newItem);
// The function inserts a new node, containing the newItem, such that it is the position-th member of the list. i.e. we assume the first element of the list is in position 1. If position is larger than the size of the list, the new item is added to the end of the list. If position < 1, the new item is added at the beginning of the list.
void addAtPosition(int position, int newItem);
// The function searched the list for the item, and if found, both prints the position of the of the item (followed by a space) and returns the position of the item in the list (positions start from 1). If not found, both prints 0 (followed by a space) and returns 0. Note that the returning type is different from what was explained in the search function in the lecture.
int search(int item);
// The function deletes the first element of the list.
void deleteFront();
// The function deletes the last element of the list.
void deleteEnd();
// The function deletes the element at the given position of the list. If the position < 1 or it is larger than the size of the list, only print ”outside range”.
void deletePosition(int position);
// The function both prints the value of the item (followed by a space) and returns the value of the item at the given position of the list, If beyond the size of the array, both prints std::numeric_limits < int >::max() 
int getItem(int position);
// The function prints the value of the items of the list from head to tail. In case of an empty list, it does not print anything
void printItems();


};
#endif

