#include <string>
#ifndef _Node_H
#define _Node_H

class Node{
private:
    int data;
    Node* next;
    //Node* previous；

public:
    Node();
    ~Node();
    Node(int dat, Node* nex);
    int getData();
    Node* getNext();
    void setData(int da);
    void setNext(Node* ne);
    //Node* getPrevious();
    //void setPrevious();

};
#endif