#include <iostream>
#include <string>

void printer(int array[10][10]){
    for(int i =0; i < 10; i++){
        for(int j = 0 ; j < 10 ; j++){
            std::cout << array[i][j]<<" ";
        }
        std::cout << "\n" ;
    }
}
