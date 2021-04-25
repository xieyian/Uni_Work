#include "Linkedlist.h"
#include "Node.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int array[5]={1,2,3,4,5};
    vector<int> in;
    for(int i=0;i<sizeof(array)/sizeof(array[0]);i++){
        in.push_back(array[i]);
    }

    Linkedlist* l= new Linkedlist(in);
    //l->printItems();
    //l->deletePosition(2);
    l->removeDupes();
    l->findmin();
    
        //l->addFront(100);
        //l->addEnd(1000);
        l->addAtPosition(100,100);
        //l->deleteFront();
        //l->deleteEnd();
        //l->deletePosition(2);
        //cout<<(l->search(3))<<" ";
    
    //l->swap(4);
    l->printItems();



    return 0;
}
