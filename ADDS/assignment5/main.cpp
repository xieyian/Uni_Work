#include "MapGeneric.h"
#include "MapAbsoluteValue.h"
#include "MapSquare.h"
#include "MapTriple.h"
#include "FilterOdd.h"
#include "FilterGeneric.h"
#include "FilterNonPositive.h"
#include "FilterForTwoDigitPositive.h"
#include "ReduceMinimum.h"
#include "ReduceGCD.h"
using namespace std;
#include <iostream>
#include <string>
#include <vector>

int main(){
    
    vector<int> a;
    string ina;
    for(int i=0;i<20;i++){
        string c="";
        while(cin>>ina || ina!=" " || ina!=","){
            c=c+ina;
            break;
        }
        int check = atoi(c.c_str());
        a.push_back(check);
    }
    
  
    
    
    //check triple
    MapTriple g;
    vector<int> check1= g.map(a);
    
    

    //check the absolutevalue
    MapAbsoluteValue abs;
    vector <int> check2 = abs.map(check1);
   
    //filter the odd numbers
    FilterOdd o;
    vector<int> checkodd=o.filter(check2);
   
    //filter the two digit postive numbers from odd
    FilterForTwoDigitPositive tdp;
    vector<int> checktdp=tdp.filter(checkodd);
   
    //find the min
    ReduceMinimum m;
    int min = m.reduce(checktdp);

    //find the gcd
    ReduceGCD gcd;
    int gg= gcd.reduce(checktdp);
    cout<<min<<" "<<gg<<endl;
    
 
    return 0;
}

