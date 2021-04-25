#include<iostream>
#include<string>
using namespace std;
extern void cpyia(int old_array[],int new_array[],int length);
int main(){
    int array1[3]={1,2,3};
    int array2[3]={};
    cpyia(array1, array2, 3);
    return 0;
}


