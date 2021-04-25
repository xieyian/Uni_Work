#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "RandomComputer.h"

void RandomComputer::setRPS(int t){
    //set RPS to a random string with length t
    string c="RPS";
    srand(time(0));
    for(int i=0; i<t;i++){
        int a=(rand() % 3+0);
        RPS=RPS+c[a];
    }
    
}

string RandomComputer::getRPS(){//return RPS
    return RPS;
}


