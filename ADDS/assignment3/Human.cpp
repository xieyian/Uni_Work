#include <string>
#include <iostream>
using namespace std;
#include "Human.h"
#include "Computer.h"



void Human::setHumRPS(){//input the RPS for human
    getline(cin,RPS);
    
}


int Human::getgames(){//get the how many times huaman want to play
    games=RPS[0]-'0';
    return games;
}

string Human::getHumRPS(){//return the input
    return RPS;
}
