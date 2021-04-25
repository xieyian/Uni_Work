#include "EfficientFibonacci.h"
#include <iostream>
using namespace std;

EfficientFibonacci::EfficientFibonacci(){//use to set default vector for calculate F(0)=0;F(1)=1
     calculated.push_back(0);
     calculated.push_back(1);
}

int EfficientFibonacci::E(int n){//use to calculate the efficientfibonacci
    int count=0;
    if(n==1){
        return 1;
    }else if(n==0){
        return 0;
    }else if(count<n-1){
        for(count;count<n-1;count++){
            calculated.push_back(calculated[count]+calculated[count+1]);
        }
    
    }
    return calculated[count]+calculated[count-1];
}
