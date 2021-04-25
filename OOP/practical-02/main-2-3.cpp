#include <iostream>
#include <stdlib.h>
extern int sum_if_a_palindrome(int integers[], int length);
int main(){
    int array[5] = {1,2,3,2,1};
    std::cout <<sum_if_a_palindrome(array,5)<< std::endl;
    return 0;
}
