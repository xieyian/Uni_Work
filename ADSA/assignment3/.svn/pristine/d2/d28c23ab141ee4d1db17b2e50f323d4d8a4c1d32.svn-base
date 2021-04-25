#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

bool checklower(string a){ // use to check input is lower case 
    bool check = true;
    for(int i = 1; i < a.size(); i++){
        if(a[i]<'a' || a[i] > 'z'){
            check = false;
        }
    }
    return check;
}

int main(){
    string out[26];
    string statues[26];
    string read;
    getline(cin,read);
    string result;
    stringstream input(read);

    for(int i = 0; i < 26; i++){ //make the empty array: out 's statues into never use 
        statues[i] = "never used";
    }
    
    while(input>>result){ // read the input 
        bool repeat = false;    
        if(result.size() <= 11 && checklower(result) == true){ //if the input size <=11 and is lower case it can read 
            char a;
            if(result[0] == 'A'){    // add the letter 
                int check = 0;
                result = result.erase(0,1); // make Aaaa to aaa
                for(int i = 0;i < 26;i++){  //check have repeat or not 
                    if(out[i] == result ){
                        repeat = true;
                    }
                }
                if(repeat == false){    //if dont have repeat read 
                    a = result[result.size()-1]; 
                    for(int i = 0; i < 26; i++ ){
                        if(a-97+i <= 25){   //add it in to the out array if there have space 
                            if(out[a-97+i].size() == 0){
                                out[a-97+i] = result;
                                statues[a-97+i] = "occupied"; 
                                break;
                            }
                        }else { //if the array is not enough long start at begin to find the space 
                            if(out[check].size() == 0){
                                out[check] = result;
                                statues[check] = "occupied"; 
                                break;
                            }else{
                                check ++;
                            }
                        }
                    }
                }           
            }else {
                result = result.erase(0,1); //make Dabc to abc
                for(int i = 0; i < 26; i++ ){   //use to delete
                    if(out[i]==result){ 
                        out[i] = "";
                        statues[i] = "tombstone";  // make the statues into tombstone
                    }else {

                    }
                }
            }
        }
        
    }

    for(int i = 0; i < 26; i++){    //print the output 
        if(out[i].size() != 0){
            cout<<out[i]<<" ";  
        }
    }

    return 0;
}