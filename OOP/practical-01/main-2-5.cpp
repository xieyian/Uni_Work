#include <iostream>
#include <stdlib.h>
extern bool descending(int array[], int n);
int main(){
    int array1[6] = {9,7,5,3,2,1};
    int array2[3] = {12,1,2};
    int array3[0];
    
    std::cout << "The array is descending: " << descending(array1, 6) << std::endl;
    std::cout << "The array is descending: " << descending(array2, 3) << std::endl;
    std::cout << "The array is descending: " << descending(array3, 0) << std::endl;
    
    return 0;
}


