#include <iostream>
#ifndef _MAPGENERIC_H
#define _MAPGENERIC_H
#include <vector>
//#include "MapAbsoluteValue.h"
//#include "MapSquare.h"

class MapGeneric{
private:
    virtual int f(int a) = 0;
public:
    std::vector<int> map(std::vector<int> vec);
    
};
#endif


