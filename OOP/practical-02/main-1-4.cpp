#include <iostream>
#include <stdlib.h>
extern void print_scaled_matrix(int array[3][3],int scale);
int main(){
    int scale = 3;
    int matrix[3][3]= {{0,1,2},{4,5,6},{8,9,1}};
    print_scaled_matrix(matrix,scale);
    return 0;
}

