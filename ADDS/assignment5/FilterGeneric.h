#ifndef _FILTERGENERIC_H
#define _FILTERGENERIC_H
#include <vector>
#include <iostream>

class FilterGeneric{
private:
    virtual bool g(int a) = 0;
public:
    std::vector<int> filter(std::vector<int> vec);
};
#endif
