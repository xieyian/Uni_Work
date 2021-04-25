#ifndef _Mutator_H
#define _Mutator_H
#include <string>
#include "Individual.h"

class Mutator{
public:
    virtual std::string mutator(Individual* i, int k);
    
    
};
#endif
