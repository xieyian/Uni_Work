int median(int array[], int n){
    int number = array[0];
    int count;
    if (n % 2 == 0 || n < 1){
        number = 0;
    }else{
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(array[i]>array[j]){
                    array[i] = array[j];
                    count = array[i];
                    array[j] = count;
                }
            }
        }
            number = array[(n+1)/2];
    }

    return number;
}
