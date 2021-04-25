#include <string>
#include <iostream>
using namespace std;
#include "FistfullODollars.h"

void FistfullODollars::setRPS(int t){
    //set RPS to RPPRP
    string c="RPP";
    for(int i=0; i<t;i++){
        RPS=RPS+c[i%3];
    }

}

string FistfullODollars::getRPS(){
    //return RPS
    return RPS;
}

