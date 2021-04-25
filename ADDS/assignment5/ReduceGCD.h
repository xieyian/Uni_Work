#ifndef _ReduceGCD_H
#define _ReduceGCD_H
#include <vector>
#include "ReduceGeneric.h"

class ReduceGCD : public ReduceGeneric{
private:
    int count = 0;
    int binaryOperator(int a, int b);
public:
    int reduce(std::vector<int> vec);
    
};
#endif


