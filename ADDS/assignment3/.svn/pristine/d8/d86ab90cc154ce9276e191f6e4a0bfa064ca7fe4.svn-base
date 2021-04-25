#include <string>
#include <iostream>
using namespace std;
#include "Referee.h"


int Referee::printoutput(string c1, string c2){
    //compare the c1 and c2 and print out a int, if int is
    //postive c1 win 
    int count=0;
    if(c1.size()==c2.size()){
        for(int i=0;i<c1.size();i++)
            if(c1[i]=='R'){
                if(c2[i]=='R'){
                    count=count+0;
                }else if(c2[i]=='P'){
                    count=count+1;
                }else if(c2[i]=='S'){
                    count=count-1;
                }else{
                    cout<<"error"<<endl;
                }
            }else if(c1[i]=='P'){
                if(c2[i]=='P'){
                    count=count+0;
                }else if(c2[i]=='S'){
                    count=count+1;
                }else if(c2[i]=='R'){
                    count=count-1;
                }else{
                    cout<<"error"<<endl;
                }
            }else if(c1[i]=='S'){
                if(c2[i]=='S'){
                    count=count+0;
                }else if(c2[i]=='R'){
                    count=count+1;
                }else if(c2[i]=='P'){
                    count=count-1;
                }else{
                    cout<<"error"<<endl;
                }
            }else{
                cout<<"error"<<endl;
            }
        }else{
        cout<<"error"<<endl;
    }
    return count;
}

