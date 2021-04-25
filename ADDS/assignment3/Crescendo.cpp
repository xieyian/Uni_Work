#include <string>
#include <iostream>
using namespace std;
#include "Crescendo.h"

void Crescendo::setRPS(int t){
    //set RPS, with to PSRPS
    string c="PSR";
    for(int i=0; i<t;i++){
        RPS=RPS+c[i%3];
    }

}

string Crescendo::getRPS(){//return RPS
    return RPS;
}

