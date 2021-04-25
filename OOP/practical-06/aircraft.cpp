#include <iostream>
#include "person.h"

//using namespace std;

person::person(std::string myName,int Salary){
    name=myName;
    money=Salary;
}

void person::setName(std::string myName){
    name=myName;
}
std::string person::getName(){
    return name;
}
void person::setSalary(int mySalary){
    money=mySalary;
}
int person::getSalary(){
    return money;
}




