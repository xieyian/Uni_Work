double weightedaverage(int array[], int n){
    double average = 0.0;
    double a;
    if(n < 1){
        average = 0.0;
    }else{
        for(int i = 0; i < n; i++){
            double count = 1;
            for(int j = i+1; j < n; j++){
                if(array[i] == array[j]){
                    count++;
                    array[j] = 0;
                }
            }
            average = average + (count * array[i])/n;
        }
    }
    return average;
}
