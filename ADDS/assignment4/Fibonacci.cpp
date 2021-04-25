#include <string>
#include <iostream>
#include "Fibonacci.h"

int Fibonacci::F(int n){//use to calculate the fibonacci
    if(n>=2){
        return F(n-1)+F(n-2);
    }else if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }
}


