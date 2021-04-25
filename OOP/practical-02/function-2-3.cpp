#include <iostream>
#include <string>
#include<math.h>
#include<vector>
#include <functional>

//int sum_if_a_palindrome(int integers[], int length){
  //  int sum = 0;
    //int
//}

int sum_if_a_palindrome(int integers[], int length){
    bool check = true;
    bool obb = false;
    bool even = false;
    int sum = 0;
    if(length >=1){
    if(length % 2 == 0){
        even = true;
    }else {
        obb = true;
    }
    if(obb == true){
        for(int i = 0;i < (length-1)/2;i++){
            if(integers[i] != integers[length-i-1]){
                check = false;
            }
        }
    }
    if(even == true){
        for(int i = 0;i < length/2;i++){
            if(integers[i] != integers[length-i-1]){
                check = false;
            }
        }
    }
    if(check == true){
        for(int i = 0;i < length; i++){
            sum += integers[i];
        }
    }else{
        sum = -2;
    }
    }else{
        sum = -1;
    }
    return sum;
}

//int sum_elements(int integers[], int length){
    
//}

