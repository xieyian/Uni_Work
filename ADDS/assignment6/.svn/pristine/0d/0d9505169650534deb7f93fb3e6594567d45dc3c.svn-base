#include "Individual.h"
#include "Mutator.h"
#include "BitFlip.h"
#include "Rearrange.h"
using namespace std;
#include <string>
#include <iostream>
#include <vector>


//which calls the mutate function on the Individual object and returns the offspring. Your execute function should decide on which mutator to use based on the actual type of the Mutator.
Individual * execute(Individual * indPtr, Mutator * mPtr, int k){
    
    Individual *i1=new Individual(mPtr->mutator(indPtr,k));
    return i1;
    
}




int main(){
    string in1,in2;
    int i1,i2;
    
    cin>>in1>>i1>>in2>>i2;
    //cout<<in1<<"!!"<<i1<<" "<<in2<<"aaaa"<<i2<<endl;
    
    Individual *a=new Individual(in1);

    a->flipBit(i1);
    
    
    Mutator *m=new Rearrange();
    Individual *b=new Individual(in2);
    
    Individual *c=execute(b,m,i2);
    
    int count = c->getMaxOnes();
    cout<<a->getString()<<" "<< c->getString()<<" "<<count<<endl;
    
    
    
    return 0;
}
