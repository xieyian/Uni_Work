#include <iostream>
#include <stdlib.h>
extern bool fanarray(int array[], int n);
int main(){
    int array1[6] = {2,4,5,6,7,9};
    int array2[3] = {12,1,2};
    int array3[0];
    
    std::cout << "The array is fanarray: " << fanarray(array1, 6) << std::endl;
    std::cout << "The array is fanarray: " << fanarray(array2, 3) << std::endl;
    std::cout << "The array is fanarray: " << fanarray(array3, 0) << std::endl;
    
    return 0;
}
