#include <string>
#include <vector>
using namespace std;
#include <iostream>

int main(){
    vector<string> a;
    string c="";
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
    
    for(int i = 0; i<a.size();i++){
        cout<<a[i]<<endl;
    }
    
    
    
    return 0;
}
