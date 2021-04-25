using namespace std;
#include "Reverse.h"
#include "Fibonacci.h"
#include "EfficientFibonacci.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    string check[4];
    
    string in[4];
    string input;
    getline(cin,input);

    for(int i=0, j=0;i<input.size();i++){//read the input
        
        if(input[i]!=' '){
            in[j]+=input[i];
        }else{
            j++;
        }

    }
  
    
    int check1;
    Reverse r;
    bool c1=true;
    for(int i=0;i<in[0].size();i++){//check the first input is int or not
        if (isdigit(in[0][i])){
        }else{
            c1=false;
            check[0]="ERROR";
        }
    }
    if(c1==true){
        int a = atoi(in[0].c_str());
        check1=r.reverseDigit(a);
        check[0]=to_string(check1);
    }
    
    
    //bool c2=true;
   
         check[1]=r.reverseString(in[1]);
    
    
    bool c3=true;
    int check3;
    Fibonacci f;
    for(int i=0;i<in[2].size();i++){//check the third input is int or not
        if (isdigit(in[2][i])){

        }else{
            c3=false;
            check[2]="ERROR";
        }
    }
    if(c3==true){
        int b = atoi(in[2].c_str());
        check3=f.F(b);
        check[2]=to_string(check3);
    }
    
    bool c4=true;
    int check4;
    EfficientFibonacci e;
    for(int i=0;i<in[3].size();i++){//check the last input is int or not
        if (isdigit(in[3][i])){

        }else{
            c4=false;
            check[3]="ERROR";
        }
        
    }
    if(c4==true){
        int cc = atoi(in[3].c_str());
        check4=e.E(cc);
        check[3]=to_string(check4);
    }
    
    for(int i=0;i<4;i++){
        if(in[i].size()==0){
            check[i]="ERROR";
        }
    }
    if(in[3][in[3].size()-1]==' '){
        check[3]="ERROR";
    }

        cout<<check[0]<<" "<<check[1]<<" "<<check[2]<<" "<<check[3]<<endl;
  
 
    return 0;

}
