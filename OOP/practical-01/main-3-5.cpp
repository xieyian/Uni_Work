#include <iostream>
#include <stdlib.h>
extern double sumeven(double array[], int n);
int main(){
    double array1[6] = {2,4,5,6,7,9};
    double array2[5] = {15,1,2,14,13};
    double array3[0];
    
    std::cout << "The sum of the even array is: " << sumeven(array1, 6) << std::endl;
    std::cout << "The sum of the even array is: " << sumeven(array2, 5) << std::endl;
    std::cout << "The sum of the even array is: " << sumeven(array3, 0) << std::endl;
    return 0;
}

