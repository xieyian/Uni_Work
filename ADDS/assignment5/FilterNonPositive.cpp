using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include "FilterNonPositive.h"

bool FilterNonPositive::g(int a){
    if(a<0){
        return true;
    }else{
        return false;
    }
}


vector<int> FilterNonPositive::filter(vector<int> vec){
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

