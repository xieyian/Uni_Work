#include <iostream>
#include <stdlib.h>
extern int minimum(int array[], int n);
int main(){
    int array1[6] = {12,11,9,7,5,8};
    int array2[3] = {12,1,2};
    int array3[0];
    
    std::cout << "The min of the arrays is: " << minimum(array1, 6) << std::endl;
    std::cout << "The min of the arrays is: " << minimum(array2, 3) << std::endl;
    std::cout << "The min of the arrays is: " << minimum(array3, 0) << std::endl;
    
    return 0;
}

