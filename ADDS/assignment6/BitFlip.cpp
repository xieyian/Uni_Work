#include "BitFlip.h"
using namespace std;
#include <string>

//The mutate function in this class “flips” the kth binary digit. If k is greater than the length of the list, we will count in circles
string BitFlip::mutator(Individual* i, int k){
    string out=i->getString();
    int length=i->getLength();
    int a = k%length-1;
    string s="";
    s+=out[a];
    return s;
   
    
}


