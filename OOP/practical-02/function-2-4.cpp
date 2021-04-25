#include<iostream>
#include<math.h>
using namespace std;

int max_integer(int integers[], int length){
    int max = integers[0];
    for(int i = 0;i < length; i++){
        if(max <= integers[i]){
            max = integers[i];
        }
    }
    return max;
}

int min_integer(int integers[], int length){
    int min = integers[0];
    for(int i = 1; i< length; i++){
        if(min >= integers[i]){
            min = integers[i];
        }
    }
    return min;
}

int sum_min_and_max(int integers[], int length, int max, int min){
    int sum = -1;
    if(length >= 1){
        sum = max + min;
    }
    return sum;
}


