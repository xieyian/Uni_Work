#include "Rearrange.h"
using namespace std;
#include <string>
#include <vector>
#include <iostream>

//In this class, the mutate function rearranges the list. The function will select the kth digit in the bitstring (again, counting in circles). This digit and all digits after it (all the way to the tail) will be moved to the start of the list. 
string Rearrange::mutator(Individual* i, int k){
    
    string out=i->getString();
    int l=i->getLength();
    int a;
    if(k%l==0){
        a=l;
    }else{
        a=k%l;
    }
    
    
    
    
    //cout<<a<<"!!!!"<<endl;
    vector <int> v;
    string output;
    
     //cout<<"!!!"<<length<<"!!!!"<<a<<endl;
    for(int i=a-1;i<l;i++){
        //cout<<"!!!"<<out[i]<<endl;
        v.push_back(out[i]);
    }
    
    for(int j=0;j<a-1;j++){
        //cout<<"!!!!!!"<<out[j]<<endl;
        v.push_back(out[j]);
    }
    
    for(int i=0;i<v.size();i++){
        //cout<<"?????"<<out[i]<<endl;
        output+=v[i];
    }
    
    return output;
}
