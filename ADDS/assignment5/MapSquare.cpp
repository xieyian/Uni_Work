#include "MapSquare.h"
using namespace std;
#include <iostream>
#include <vector>

int MapSquare::f(int v){
    return v*v;
}


vector<int> MapSquare::map(vector<int> vec){
    if(count<20){
        int a= f(vec[0]);
        vv.push_back(a);
        //cout<<vec.size()<<"!"<<vv.size()<<"!"<<count<<"!!"<<a<<endl;
        vec.erase(vec.begin());
        count++;
        return map(vec);
    }else{
        return vv;
    }
    
}
