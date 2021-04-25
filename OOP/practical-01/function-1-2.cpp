double average(int array[], int n){
    double average = 0.0;
    double total = 0.0;
    if(n < 1){
        average = 0.0;
    }else{
        for(int i = 0; i < n; i++){
            total += array[i];
        }
        average = total/n;
    }
    return average;
}
