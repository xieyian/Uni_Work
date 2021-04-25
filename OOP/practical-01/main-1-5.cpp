#include <iostream>
#include <stdlib.h>
extern int count_even(int number);
int main(){
    std::cout << "The count is: " << count_even(1) << std::endl;
    std::cout << "The count is: " << count_even(5) << std::endl;
    std::cout << "The count is: " << count_even(8) << std::endl;
    std::cout << "The count is: " << count_even(9) << std::endl;
    return 0;
}

