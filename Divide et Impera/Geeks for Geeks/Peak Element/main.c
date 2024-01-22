#include <stdio.h>
#include <stdlib.h>



int findPeak(int *arr, int l, int r){
    
    if(l == r){
        return r; 
    }


    int m = (l+r)/2; 

    if( (arr[m] > arr[m-1]) && (arr[m] > arr[m+1]) ){
        return m; 
    }

    if(arr[m-1] > arr[m]){
        return findPeak(arr, l, m-1); 
    }

    if(arr[m+1] >  arr[m]){
        return findPeak(arr, m+1, r); 
    }



}





int main(){

    FILE* f = NULL; 
    f = fopen("input.txt", "r"); 

    if(!f){
        printf("Error in opening file"); 
        return 0; 
    }


    int N, X, T, I=1; 

    fscanf(f, "%d", &T); 

    while(T--){
        fscanf(f, "%d", &N);  

        int values[N]; 

        for(int i=0; i<N; i++){
            fscanf(f, "%d", &values[i]); 
        }

        printf("Case# %d: %d \n", I, findPeak(values, 0, N-1)); 
        I++; 

    }    


}



