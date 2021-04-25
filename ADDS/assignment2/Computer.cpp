#include <string>
#include <iostream>
using namespace std;
#include "Computer.h"
#include "Human.h"



void Computer::setComRPS(int t){//set the RPS for computer

    for(int i=0; i<t;i++)
        RPS="R "+RPS;
}


string Computer::getComRPS(){//return the RPS for computer
    return RPS;
}



