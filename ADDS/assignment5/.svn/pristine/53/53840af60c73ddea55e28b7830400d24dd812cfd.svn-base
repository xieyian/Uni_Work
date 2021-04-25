using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include "FilterOdd.h"

bool FilterOdd::g(int a){
    if(a%2==1){
        return true;
    }else{
        return false;
    }
}


vector<int> FilterOdd::filter(vector<int> vec){
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

