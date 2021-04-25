#include <string>
#include <iostream>
#ifndef _CRESCENDO_H
#define _CRESCENDO_H
#include "Computer.h"

class Crescendo : public Computer{
private:
    string RPS;
public:
    virtual void setRPS(int t);//set the RPS 
    virtual std::string getRPS();//return the RPS
};
#endif
