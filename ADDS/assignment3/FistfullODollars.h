#include <string>
#include <iostream>
#ifndef _FISTFULLODOLLARS_H
#define _FISTFULLODOLLARS_H
#include "Computer.h"

class FistfullODollars : public Computer{
private:
    string RPS;
public:
    virtual void setRPS(int t);//set RPS
    virtual std::string getRPS();//return  RPS
};
#endif

