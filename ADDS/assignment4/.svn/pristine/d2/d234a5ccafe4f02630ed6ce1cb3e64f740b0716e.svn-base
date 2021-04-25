using namespace std;
#include "Reverse.h"
#include <iostream>
#include <string>
#include <sstream>
int Reverse::reverseDigit(int value){//The function takes in an non-negative int value and reverses the digits using recursion. The “reversed” int is then returned.
    string words=to_string(value);//change int to string
    
    if(words.size()>1){
        if(words[words.size()-1]!='0'){//delete the 0 for example 6400->640->64
            intstring+=words[words.size()-1];
        }
        words.erase(words.size()-1,1);
        check = atoi(words.c_str());//change string to int
        return reverseDigit(check);

    }else{
        intstring+=words[words.size()-1];
        reint= atoi(intstring.c_str()); 
        return reint;
    }
}

string Reverse::reverseString(string words){// The function takes in a std::string and returns the reversed string
    if(words.size()>0){
        reveroutput+=words[words.size()-1];
        words.erase(words.size()-1,1);//delete the last letter of string
        return reverseString(words);
    }else{
        return reveroutput;
    }
}