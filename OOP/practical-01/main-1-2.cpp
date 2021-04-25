#include <iostream>
#include <stdlib.h>
extern double average(int array[], int n);
int main(){
    int array1[4] = {12,1,2,4};
    int array2[0];
    
    
    std::cout << "The avergae is: " << average(array1, 4) << std::endl;
    std::cout << "The average is: " << average(array2, 0) << std::endl;
    return 0;
}

