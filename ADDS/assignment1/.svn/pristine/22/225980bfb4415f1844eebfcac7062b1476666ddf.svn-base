#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cctype>
#include <cstring>
#include <cstdio>
using namespace std;
#include "Palindrome.h"

Palindrome::Palindrome(){

}


void Palindrome::removeNonLetters(string *s){
    for(int i=0; i<(*s).length();i++){
        if(isalpha( (*s)[i] )==0){
            (*s).erase((*s).begin()+i);
            i--;
        }
    }

    
}

void Palindrome::lowerCase(string *st){
    for(int i=0; i<(*st).length();i++){
       (*st)[i]=tolower((*st)[i]);
    }

}

string Palindrome::isPalindrome(string *str){
    
    /*for(int i=0; i<(*str).length();i++){
        cout<<(*str)[i];
    }
    cout<<"///";
    for(int i=0; i<(*str).length();i++){
        cout<<(*str)[(*str).length()-i-1];
    }
    cout<<endl;*/
    
    for(int i=0; i<(*str).size();i++){
        if((*str)[i]!=(*str)[(*str).size()-i-1]){
            
            return "No";
        }
    }
    
    return "Yes";
}


Palindrome::~Palindrome(){
    
}
