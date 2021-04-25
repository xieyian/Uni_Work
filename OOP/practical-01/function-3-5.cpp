double sumeven(double array[], int n){
    double sum = 0;
    if(n < 1){
        sum = 0;
    }else{
        for(int i = 0; i < n; i++){
            if(i % 2 == 1){
                sum +=array[i];
            }
        }
    }
    return sum;
}
