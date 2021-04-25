#include <iostream>
#include <vector>
#ifndef _EFFICIENTFIBONACCI_H
#define _EFFICIENTFIBONACCI_H

class EfficientFibonacci{
private:
    std:: vector <int> calculated;
public:
    EfficientFibonacci();//use to set default vector for calculate F(0)=0;F(1)=1
    int E(int n);//use to calculate the efficientfibonacci
};
#endif
