int minimum(int array[], int n){
    int min = array[0];
    if(n<1){
        min = 0;
    }else{
        for(int i = 0;i < n; i++){
            if(array[i] <= min){
                min = array[i];
            }
        }
    }
    return min;
}
