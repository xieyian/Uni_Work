#include <iostream>
#ifndef _MAPABSOLUTEVALUE_H
#define _MAPABSOLUTEVALUE_H
#include <vector>
#include "MapGeneric.h"

class MapAbsoluteValue: public MapGeneric{
private:
    int count = 0;
    std::vector<int> vv;
    int f(int v);
public:
    std::vector<int> map(std::vector<int> vec);
};
#endif
