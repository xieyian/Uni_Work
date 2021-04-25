#include <iostream>
#include "person.h"

using namespace std;

// main program
int main()
{
    person a("aaa",111);
    person b("bbb",222);
    person c("ccc",333);
    person d("ddd",444);
    a.setName("AAAA");
    a.setSalary(100);
    b.setName("BBBB");
    b.setSalary(200);
    c.setName("CCCC");
    c.setSalary(300);
    d.setName("DDDD");
    d.setSalary(400);
    
    return 0;
}


