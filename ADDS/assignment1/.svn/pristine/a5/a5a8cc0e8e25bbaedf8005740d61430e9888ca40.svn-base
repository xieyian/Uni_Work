#include "Linkedlist.h"
#include "Node.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int array[10]={1,2,2,2,4,4,4,4,2,2};
    vector<int> in;
    for(int i=0;i<sizeof(array)/sizeof(array[0]);i++){
        in.push_back(array[i]);
    }

    Linkedlist* l= new Linkedlist(in);
    //l->printItems();
    //l->deletePosition(2);
    l->removeDupes();
    l->findmin();
    //l->swap(4);
    l->printItems();



    return 0;
}
