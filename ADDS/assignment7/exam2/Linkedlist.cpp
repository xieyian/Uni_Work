using namespace std;
#include "Linkedlist.h"
#include <vector>
#include <iostream>

Linkedlist::Linkedlist(){
    head= nullptr;
    length=0;
}

Linkedlist:: Linkedlist(vector<int> vect){
     pointer = new Node();
     head = pointer;
     Node * p1;
     length = vect.size();
     for(int i=0 ; i<vect.size(); i++){
         if(i == 0){
             pointer->setData(vect[i]);
             pointer->setNext(nullptr);
         }else{
            p1 = new Node();
            p1->setData(vect[i]);
            p1->setNext(nullptr);
            pointer->setNext(p1);
            pointer = p1;
         }
     }
}

void Linkedlist::addFront(int newItem){
    Node * p1=new Node;
    p1->setData(newItem);
    p1->setNext(head);
    head=p1;
    length++;
}

void Linkedlist::addEnd(int newItem){
    Node * p1=new Node;
    pointer->setNext(p1);
    p1->setData(newItem);
    pointer=p1;
    length++;
    
}

void Linkedlist::addAtPosition(int position, int newItem){
    if(position<1){
        addFront(newItem);
    }else if(position>length){
        addEnd(newItem);
        
    }else{
        Node* head3=new Node;
        Node* head2=new Node;
        Node * p1=new Node;
        head2=head;
        head3=head;
        for(int i=0;i<position-1;i++){
            head3=head3->getNext();
        }
        
        for(int i=0;i<position;i++){
            head2=head2->getNext();
        }
        head3->setNext(p1);
        p1->setData(newItem);
        p1->setNext(head2);
        length++;
        
    }
}

void Linkedlist::removeDupes(){ // removes all duplicate entries in
    Node * check=new Node;
    Node* c=new Node;
    c=head;
    for(int i=0;i<length;i++){
        check=head;
        int count=0;
        int n=c->getData();
        
        for(int j=0;j<length;j++){
            if(check->getData()==n){
                count++;
                if(count>1){
                    deletePosition(j);
                    count=1;
                }
            }
            check=check->getNext();
        }
        c=c->getNext();
    }
}

void Linkedlist::swap(int n){
    int min;
    int n1;
    min = (findmin()->getData());
    Node * next=new Node;
    next=head;
    Node* minn;
    minn=findmin();
    for(int i=0;i<n;i++){
        next=next->getNext();
    }
    n1=next->getData();
    next->setData(min);
    minn->setData(n1);

}

Node* Linkedlist::findmin(){
    Node * min= new Node;
    Node * check= new Node;
    min=head;
    check=head;
    for(int i=0;i<length-1;i++){
        if(min->getData() > check->getData()){
            min=check;
            check=check->getNext();
        }else{
            check=check->getNext();
        }
    }
    return min;
}


void Linkedlist::deletePosition(int position){

    Node * left;
    Node * right;
    position=position-1;
    left=head;
    right=head;
    if(position>length-1){
        cout<<"outside range";
    }else if(position<0){
        cout<<"outside range";
    }else{
      for(int i=0; i<position-1; i++){
        left=left->getNext();
      }
      for(int i=0; i<position+1; i++){
        right=right->getNext();
      }
      if(position==1-1){
        Node * f=head;
        head=head->getNext();
        delete f;
        length--;
      }else{
        left->setNext(right);
        length--;
      }
    }

}

int Linkedlist::search(int item){
    Node * n;
       n=head;
       for(int i=0;i<length;i++){
           if((n->getData())!=item){
               n=n->getNext();
           }else if((n->getData())==item){
               return i+1;
           }
       }
}

void Linkedlist::deleteFront(){
    Node * f=head;
    head=head->getNext();
    delete f;
    length--;
}

void Linkedlist::deleteEnd(){
    Node * e1=pointer;
    Node * e2=head;
    for(int i=0;i<length-2;i++){
        e2=e2->getNext();
    }
    pointer=e2;
    delete e1;
    length--;
}

void Linkedlist::printItems(){
    Node* newhead=head;
    for(int i=0; i<length;i++){
        cout<<newhead->getData()<< " ";
        newhead=newhead->getNext();
    }
}
    
Linkedlist::~Linkedlist(){
    Node * remove=new Node;
    remove=head;
    for(int i=0;i<length;i++){
        head=head->getNext();
        delete remove;
        remove=head;
    }
}
