#include <string>
#include <iostream>
using namespace std;
#ifndef _HUMAN_H
#define _HUMAN_H


class Human{
    
private:
    string RPS;
    int games;
    
public:

    void setHumRPS();//input the RPS for human
    int getgames();//get the how many times huaman want to play
    string getHumRPS();//return the input


    
    
    
};
#endif
