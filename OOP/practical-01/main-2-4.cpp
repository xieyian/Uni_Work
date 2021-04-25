#include <iostream>
#include <stdlib.h>
extern bool ascending(int array[], int n);
int main(){
    int array1[6] = {2,4,5,5,4,2};
    int array2[3] = {12,1,12};
    int array3[0];
    
    std::cout << "The array is ascending: " << ascending(array1, 6) << std::endl;
    std::cout << "The array is ascending: " << ascending(array2, 3) << std::endl;
    std::cout << "The array is ascending: " << ascending(array3, 0) << std::endl;
    
    return 0;
}


