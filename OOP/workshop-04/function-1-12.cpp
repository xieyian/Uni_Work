int size_of_variable_star_arr(){
    int a[3],*p[3];
    for(int i = 0; i< 3; i++){
        p[i] = &a[i];
    }
    
    int *arr = new int[3];
    for(int i = 0; i< 3; i++){
        arr[i] = *p[i];
        
    }
    delete [] arr;
    return sizeof(*arr);
    
}