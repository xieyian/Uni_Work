bool ascending(int array[], int n){
    bool check = true;
    int count = array[0];
    if (n <= 0){
        check = false;
    }else{
        for (int i = 0; i < n; i++){
            if(count <= array[i]){
                count = array[i];
            }else {
                check = false;
            }
        }
    }
    return check;
}
