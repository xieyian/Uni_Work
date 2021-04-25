#include <string>
#include <iostream>
#ifndef _COMPUTER_H
#define _COMPUTER_H


class Computer{
    
private:
    string RPS;
    
public:
    Computer();
    virtual void setRPS(int t);//set the RPS for computer
    virtual std::string getRPS();//return the RPS for computer
    
    
};
#endif
