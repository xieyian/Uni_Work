#include <iostream>
#include <stdlib.h>
extern int maximum(int array[], int n);
int main(){
    int array1[6] = {13,11,9,7,5,8};
    int array2[3] = {12,1,2};
    int array3[0];
    
    std::cout << "The max of the arrays is: " << maximum(array1, 6) << std::endl;
    std::cout << "The max of the arrays is: " << maximum(array2, 3) << std::endl;
    std::cout << "The max of the arrays is: " << maximum(array3, 0) << std::endl;
    
    return 0;
}

