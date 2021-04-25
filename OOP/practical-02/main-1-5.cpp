#include <iostream>
#include <stdlib.h>
extern void print_summed_matrices(int array1[3][3],int array2[3][3]);
int main(){
    int m [3][3] = {{0,1,2},{4,5,6},{8,9,9}};
    int matrix[3][3]= {{0,1,2},{4,5,6},{8,9,1}};
    print_summed_matrices(m,matrix);
    return 0;
}

