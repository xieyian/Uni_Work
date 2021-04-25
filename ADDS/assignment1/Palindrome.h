#include <string>
#include <iostream>
using namespace std;
#ifndef _PALINDROME_H
#define _PALINDROME_H

class Palindrome{
public:
    Palindrome();
    ~Palindrome();
    
    void removeNonLetters(string *s);
    void lowerCase(string *st);
    string isPalindrome(string *str);
};
#endif
