using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include "ReduceMinimum.h"


int ReduceMinimum::binaryOperator(int a, int b){
    if(a>b){
        return b;
    }else{
        return a;
    }
}

int ReduceMinimum::reduce(vector<int> vec){
    if(count<vec.size()-1){
        vec[0]=binaryOperator(vec[0],vec[count+1]);
        count++;
        return reduce(vec);
    }else{
        return vec[0];
    }
}
