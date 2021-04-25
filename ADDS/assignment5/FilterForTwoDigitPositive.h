#include <vector>
#include <iostream>
#ifndef _FilterForTwoDigitPositive_H
#define _FilterForTwoDigitPositive_H
#include "FilterGeneric.h"


class FilterForTwoDigitPositive: public FilterGeneric{
private:
    int count = 0;
    std::vector<int> vv;
    bool g(int a);
public:
    std::vector<int> filter(std::vector<int> vec);
};
#endif

