#include <vector>
#include <iostream>
#include <string>
#include "ReduceGCD.h"
using namespace std;

int ReduceGCD::binaryOperator(int a, int b){
    if(a>b){
        if(a%b!=0){
            return binaryOperator(b,a%b);
        }else{
            return b;
        }
    }else{
        if(b%a!=0){
            return binaryOperator(a,b%a);
        }else{
            return a;
        }
    }
}

int ReduceGCD::reduce(vector<int> vec){
    if(count<vec.size()-1){
        vec[0]=binaryOperator(vec[0],vec[count+1]);
        count++;
        return reduce(vec);
    }else{
        return vec[0];
    }
}
