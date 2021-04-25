#include <string>
#include <iostream>
using namespace std;
#include "Bureaucrat.h"
#include "Avalanche.h"
#include "Computer.h"
#include "Toolbox.h"
#include "Crescendo.h"
#include "PaperDoll.h"
#include "FistfullODollars.h"
#include "RandomComputer.h"
#include <sstream>
#include "Referee.h"
#include "Tournament.h"


void Tournament::setinput(){
    //set the input
    getline(cin,input);
    
    int index=0;
    int count=0;
    for(int i = 0; i < input.size(); i++){//separete the input with space and put them into player[8]
        if(input[i]==' '){
            for(int j=index;j<i;j++){
                player[count]+=input[j];
                index=i+1;
            }
            count++;
            
            
        }
        else if(count==7){
            player[7]+=input[i];
        }
        
        
    }
}

string Tournament::getwinner(int t){
    string winner;
    string winnername;
    Computer* p[8];
    //create the new object according the player[8]
    
    for(int i=0;i<8;i++){
        if(player[i]=="Bureaucrat"){
            p[i]=new Bureaucrat();
        }
        else if(player[i]=="Avalanche"){
            p[i]=new Avalanche();
        }
        else if(player[i]=="Toolbox"){
            p[i]=new Toolbox();
        }
        else if(player[i]=="Crescendo"){
            p[i]=new Crescendo();
        }
        else if(player[i]=="PaperDoll"){
            p[i]=new PaperDoll();
        }
        else if(player[i]=="FistfullODollars"){
            p[i]=new FistfullODollars();
        }else{
            cout<<"error"<<endl;
        }
        
    }
    

    for(int i=0;i<8;i++){//set the RPS for those new objects
        p[i]->setRPS(t);
    }
    
    
    Referee r;
    //round 1
    //compare p[8] and put the winner into round1[4]
    int check1;
    Computer* round1[4];

    for(int i=0;i<8;i=i+2){
        check1=r.printoutput(p[i]->getRPS(),p[i+1]->getRPS());
        if(check1>=0){
            round1[i/2]=p[i+1];
        }else{
            round1[i/2]=p[i];
        }
    }
    
    
    //round 2
    //compare the round2[4] and putt he winner into round2[2]
    int check2;
    Computer* round2[2];
    for(int i=0;i<4;i=i+2){
    check2=r.printoutput(round1[i]->getRPS(),round1[i+1]->getRPS());
        if(check2>=0){
            round2[i/2]=round1[i+1];
        }else{
            round2[i/2]=round1[i];
        }
    }
    //cout<<r.printoutput(p[0]->getRPS(),p[1]->getRPS())<<endl;
    
    //final round
    //compare the round2[2] and select the winner and print out the winnername 
    int check=r.printoutput(round2[0]->getRPS(),round2[1]->getRPS());
    if(check>=0){
        winner=round2[1]->getRPS();
    }else{
        winner=round2[0]->getRPS();
    }
    for(int i=0;i<8;i++){
        if(winner==p[i]->getRPS())
        winnername=player[i];
        
    }
    
    
    
    for(int i=0;i<8;i++){
        delete p[i];
    }
    return winnername;
}

