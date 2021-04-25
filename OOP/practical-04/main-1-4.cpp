#include<iostream>
#include<string>
using namespace std;
extern void cpyda(double *old_array,double *new_array,int length);
int main(){
    double array1[3][2]={{1,2},{3,4},{5,6}};
    double array2[3][2]={};
    cpyda( *array1, *array2, 3);
    return 0;
}

