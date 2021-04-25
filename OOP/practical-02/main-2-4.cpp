#include<iostream>
#include<math.h>
using namespace std;
extern int sum_min_and_max(int integers[], int length, int max, int min);
extern int max_integer(int integers[], int length);
extern int min_integer(int integers[], int length);

int main(){
    int array[6]={1,2,3,4,5,6};
    int max, min;
    max = max_integer(array,6);
    min = min_integer(array,6);
    cout<<sum_min_and_max(array,6,max,min)<<endl;
    return 0;
}
