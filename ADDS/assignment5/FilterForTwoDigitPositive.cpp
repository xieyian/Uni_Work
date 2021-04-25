using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include "FilterForTwoDigitPositive.h"

bool FilterForTwoDigitPositive::g(int a){
    if(a>=10 && a<=99){
        return true;
    }else{
        return false;
    }
}


vector<int> FilterForTwoDigitPositive::filter(vector<int> vec){
    if(count<vec.size()){
        if(g(vec[count])==true){
            vv.push_back(vec[count]);
        }
        count++;
        return filter(vec);
    }else{
        return vv;
    }
}

