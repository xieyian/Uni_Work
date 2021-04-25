#include<iostream>
#include<string>
using namespace std;
extern void copy_2d_strings(string first[][2], string second[][2], int n);
int main(){
    string array1[3][2]={{"ab","cd"},{"ef","gh"},{"ij","kl"}};
    string array2[3][2]={};
    copy_2d_strings(array1, array2, 3);
    return 0;
}
