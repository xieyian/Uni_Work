int maximum(int array[], int n){
    int max = array[0];
    if(n<1){
        max = 0;
    }else{
        for(int i = 0;i < n; i++){
            if(array[i] >= max){
                max = array[i];
            }
        }
    }
    return max;
}

