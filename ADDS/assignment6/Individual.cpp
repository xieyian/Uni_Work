#include "Individual.h"
using namespace std;
#include <string>
#include <iostream>
#include <vector>


Individual::Individual(int l){
    length=l;
    for(int i=0;i<length;i++){
        strDNA+="0";
    }

}


Individual::Individual(string stDNA){
    strDNA=stDNA;
}


//The function outputs a binary string representation of the bitstring list (e.g.“01010100”).
string Individual::getString(){
    return strDNA;
}

//The function returns the bit value at position pos. It should return -1 if pos is out of bound..
int Individual::getBit(int pos){
    int bit;
    if(pos>=length){
        return 0;
    }else{
        return strDNA[pos];
    }
}

//The function takes in the position of the certain bit and flip the bit value.
void Individual::flipBit(int pos){
    int l=strDNA.size();
    int p;
    if(pos%l==0){
        p=l-1;
    }else{
        p=pos%l-1;
    }
    //cout<<p<<"!!!"<<l<<endl;

    if(strDNA[p]=='1'){
        strDNA[p]='0';
    }else {
        strDNA[p]='1';
    }
}

//The function returns the longest consecutive sequence of ‘1’ digits in the list (e.g. calling the function on “1001110” will obtain 3).
int Individual::getMaxOnes(){
    vector <int> n;
    int count=0;
    for(int i=0;i<strDNA.size();i++){
       if(strDNA[i]=='1'){
            count++;
            n.push_back(count);
       }else{
           count=0;
           n.push_back(count);
       }
    }
    int max=n[0];
    for(int i=0;i<n.size();i++){
        if(max<=n[i]){
            max=n[i];
        }
    }
    
    return max;
}

//The function returns the length of the list.
int Individual::getLength() {
    return strDNA.size();
}
