#include<iostream>
using namespace std;
void print_scaled_matrix(int array[3][3],int scale){
    for(int i = 0;i < 3;i ++){
        for(int j = 0;j < 3;j++){
            if(j!=2||(i==0 && j==0)){
                cout<<scale*array[i][j]<<" ";
            }else if(j==2){
                cout<<scale*array[i][j];
                cout<<"\n";
                if(i==j && i==2){
                    cout<<endl;
                }
            }
        }
    }
}
