#include <iostream>
#ifndef _MAPTRIPLE_H
#define _MAPTRIPLE_H
#include <vector>
#include "MapGeneric.h"

class MapTriple: public MapGeneric{
private:
    int count = 0;
    std::vector<int> vv;
    int f(int v);
public:
    std::vector<int> map(std::vector<int> vec);
};
#endif
