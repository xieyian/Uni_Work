bool fanarray(int array[], int n){
    bool check = true;
    if(n % 2 == 1 || n < 1){
        check = false;
    }else{
        for (int i = 0; i < n; i++){
            if (array[i] == array[n-i]){
                check = true;
            }
        }
    }
    return check;
}
