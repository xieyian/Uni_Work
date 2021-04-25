int identity(int array[10][10]){
    int check = 1;
    for(int i = 0; i < 10; i++){
        if(array[i][i]!=1){
            check = 0;
        }
    }
    return check;
}
