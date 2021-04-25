#include <vector>
#include <iostream>
#ifndef _FILTERODD_H
#define _FILTERODD_H
#include "FilterGeneric.h"


class FilterOdd: public FilterGeneric{
private:
    int count = 0;
    std::vector<int> vv;
    bool g(int a);
public:
    std::vector<int> filter(std::vector<int> vec);
};
#endif
