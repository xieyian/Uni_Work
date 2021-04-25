#include <iostream>
#include "meerkat.h"

//using namespace std;

meerkat::meerkat(){
    name="?";
    age=0;
}

void meerkat::setName(std::string meerName){
    name=meerName;
    
}

std::string meerkat::getName(){
    return name;
}

void meerkat::setAge(int meerAge){
    age=meerAge;
}

int meerkat::getAge(){
    return age;
}





