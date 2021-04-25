#include "MapTriple.h"
using namespace std;
#include <iostream>
#include <string>
#include <vector>
int MapTriple::f(int v){
    return v*3;
}

vector<int> MapTriple::map(vector<int> vec){
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
