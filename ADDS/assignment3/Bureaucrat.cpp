#include <string>
#include <iostream>
using namespace std;
#include "Bureaucrat.h"

void Bureaucrat::setRPS(int t){
    //set the RPS to rock and play t games
    for(int i=0; i<t;i++)
        RPS="P"+RPS;
}

string Bureaucrat::getRPS(){
    return RPS;
}

