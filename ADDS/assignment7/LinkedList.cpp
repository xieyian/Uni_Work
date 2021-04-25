#include "LinkedList.h"
#include <string>
#include <iostream>
using namespace std;

LinkedList::LinkedList(){
    head= nullptr;
    length=0;
}

//A constructor that takes an array of integers and makes a linked list, containing all the elements of the array, in the same order. As the second parameter, it takes the size of the array.
LinkedList::LinkedList(int a[],int sizeofa){
    head = nullptr;
    length=0;
    for(int i=0;i<sizeofa;i++){
       
        addEnd(a[i]);
    }
    length=sizeofa;
    
}

//A destructor that manually deletes all the elements that are still in the list.
LinkedList::~LinkedList(){
    for(int i=0;i<length;i++){
        deleteFront();
    }
}

//The function inserts a new Node, containing the newItem, at the beginning of the list.
void LinkedList::addFront(int newItem){
    Node * p1=new Node;
    p1->data=newItem;
    p1->next=head;
    head=p1;
    if(length<=1){
        end=p1;
    }
    length++;
}

// The function inserts a new Node, containing the newItem, at the end of the list.
void LinkedList::addEnd(int newItem){
    Node * p1=new Node;
    p1->data=newItem;
    p1->next=nullptr;
    if(length==1){
        head->next=p1;
        end=p1;
    }else if(length==0){
        head=p1;
        end=p1;
    }else{
        end->next=p1;
        end=p1;
    }
    length++;

} 

// The function inserts a new Node, containing the newItem, such that it is the position-th member of the list. i.e. we assume the first element of the list is in position 1. If position is larger than the size of the list, the new item is added to the end of the list. If position < 1, the new item is added at the beginning of the list.
void LinkedList::addAtPosition(int position, int newItem){
    if(position<1){
        addFront(newItem);
    }else if(position>length){
        addEnd(newItem);
    }else{
    Node * p1=new Node;
    p1->data=newItem;
    position=position-1;
    Node * left;
    Node * right;
    left=head;
    right=head;
    
    for(int i=0;i<position-1;i++){
        left=left->next;
    }
    
    for(int i=0;i<position;i++){
        right=right->next;
    }
    
    p1->next=right;
    left->next=p1;
    length++;
    }
} 

// The function searched the list for the item, and if found, both prints the position of the of the item (followed by a space) and returns the position of the item in the list (positions start from 1). If not found, both prints 0 (followed by a space) and returns 0. Note that the returning type is different from what was explained in the search function in the lecture.
int LinkedList::search(int item){
    Node * n;
    n=head;
    for(int i=0;i<length;i++){
        if((n->data)!=item){
            n=n->next;
        }else if((n->data)==item){
            return i+1;
        }
        
    }
        
} 

// The function deletes the first element of the list.
void LinkedList::deleteFront(){
    Node * f=head;
    head=head->next;
    delete f;
    length--;
} 

// The function deletes the last element of the list.
void LinkedList::deleteEnd(){
    Node * e1=end;
    Node * e2=head;
    for(int i=0;i<length-2;i++){
        e2=e2->next;
    }
    end=e2;
    delete e1;
    length--;
    
} 

// The function deletes the element at the given position of the list. If the position < 1 or it is larger than the size of the list, only print ”outside range”.
void LinkedList::deletePosition(int position){

    Node * left;
    Node * right;
    position=position-1;  // The nth element we want to delete actually has an index (n-1)

    // For example, given "abcde", want to delete position3, then left=b, right=d
    left=head;
    right=head;
    if(position>length-1){
        cout<<"outside range";
    }else if(position<0){
        cout<<"outside range";
    }else{
      for(int i=0; i<position-1; i++){
        left=left->next;
      }
      for(int i=0; i<position+1; i++){
        right=right->next;
      }
      if(position==1-1){
        deleteFront();
      }else{
        delete left->next;  //delete "c"
        left->next=right;
        length--;
      }
    }

} 

// The function both prints the value of the item (followed by a space) and returns the value of the item at the given position of the list, If beyond the size of the array, both printstd s::numeric_limits < int >::max()
int LinkedList::getItem(int position){
    int out;
    Node * n=head;
    for(int i=0;i<position-1;i++){
        n=n->next;
    }
    out=n->data;
    return out;

} 

// The function prints the value of the items of the list from head to tail. In case of an empty list, it does not print anything
void LinkedList::printItems(){
    
    Node * newhead=head;
     int i=1;
     while(newhead){
         if(i!=length){
         cout<<newhead->data<<" ";
         newhead=newhead->next;
         i++;
         }else if(i==length){
             cout<<newhead->data<<endl;
             break;
         }
     }
    
} 
