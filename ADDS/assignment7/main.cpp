//#include "Node.h"
#include "LinkedList.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<string> a;
    vector<int> in;
    int in1=0;
    int in2=0;
    
    
    string c="";
    string method="";
    string input;
    getline(cin,input);
    input=input+" ";
    
   for(int i=0;i<input.size();i++){
       if(input[i]!=' '){
            c=c+input[i];
        }else if(input[i]==' '&& c!=""){
            a.push_back(c);
            c="";
        }
    }
    
   
    /*for(int i=0;i<input.size();i++){
        if(a[i]=="AF"|| a[i]=="AE" || a[i]=="AP" ||a[i]=="S"|| a[i]=="DF"||a[i]=="DE"||a[i]=="DP" || a[i]=="GI"){
            method=a[i];}}
              for(int j=0;j<i;j++){
                c=a[j];
                int check = atoi(c.c_str());
                in.push_back(check);
            }
            string ch1=a[i+1];
            in1=atoi(ch1.c_str());
            string ch2=a[i+2];
            in2=atoi(ch2.c_str());
            
        }
    }
    
    for(int i=0; i<input.size(); i++){
      if(input[i]!=' '  && i!=input.size()-1){
        c+=input[i];
      }else if(input[i]==' ' && i!=input.size()-1){
        a.push_back(c);
        c="";
      }else if(i==input.size()-1){
        c+=input[i];
        a.push_back(c);
        c="";
      }
    }*/
    method=a[a.size()-3];
    
    for(int i=0; i<a.size()-3; i++){
        in.push_back(stoi(a[i]));
    }
    
    in1=stoi(a[a.size()-2]);
    in2=stoi(a[a.size()-1]);
    
    int array[in.size()];
    for(int i=0;i<in.size();i++){
        array[i]=in[i];
    }
    
   
    //int len=sizeof(array)/sizeof(*array);
    LinkedList* l=new LinkedList(array,in.size());


    if(method=="AF"){
        l->addFront(in1);
    }else if(method=="AE"){
        l->addEnd(in1);
    }else if(method=="AP"){
        l->addAtPosition(in1,in2);
    }else if(method=="DF"){
        l->deleteFront();
    }else if(method=="DE"){
        l->deleteEnd();
    }else if(method=="DP"){
        l->deletePosition(in1);
    }else if(method=="GI"){
        cout<<(l->getItem(in1))<<" ";
        
    }else if(method=="S"){
        cout<<(l->search(in1))<<" ";
        
    }
        
    
    //cout<<"!!!"<<in1<<method<<"!!"<<endl;
    l->printItems();

    return 0;
}

