#include <string>
#include <iostream>
using namespace std;
#include "Referee.h"
#include "Human.h"
#include "Computer.h"

void Referee::printoutput(Human h, Computer c){
    //used to compare and print the ouput
    string output;
    string p;
    p=h.getHumRPS().erase(0,2);
    //cout<<p<<endl;
    //cout<<c.getComRPS()<<endl;
    
    int time= h.getgames();
    for(int i=0;i<time;i++){
        if(p[i*2]=='R'){
            if(c.getComRPS()[i*2]=='R'){
                output+="T ";
            }
        }
        else if(p[i*2]=='P'){
            if(c.getComRPS()[i*2]=='R'){
             output+="W ";
            }
            
        }
        else if(p[i*2]=='S'){
            if(c.getComRPS()[i*2]=='R'){
            output +="L ";
            }
            
        }
        else{
            output="error";
        }
    }
    
    output.erase(output.size()-1,1);
    
    cout<< output <<endl;
}
