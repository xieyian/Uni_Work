#include <string>
#include <iostream>
using namespace std;
#include "Toolbox.h"

void Toolbox::setRPS(int t){
    //set RPS to SSSSS
    for(int i=0; i<t;i++)
        RPS="S"+RPS;
}

string Toolbox::getRPS(){//return RPS
    return RPS;
}

