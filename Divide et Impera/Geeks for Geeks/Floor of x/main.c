#include <stdio.h> 
#include <stdlib.h>

int findFloor(int* arr, int l, int r, int x){

    if(l>r){
        return r; 
    }

    int m = (l+r)/2; 

    if(arr[m] > x){
        return findFloor(arr, l, m-1, x); 
    }

    if(arr[m] < x){
        return findFloor(arr, m+1, r, x); 
    }

    if(arr[m] == x){
        return m-1; 
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
        fscanf(f, "%d", &X); 

        int values[N]; 

        for(int i=0; i<N; i++){
            fscanf(f, "%d", &values[i]); 
        }

        printf("Case# %d: %d \n", I, findFloor(values, 0, N-1, X)); 
        I++; 

    }    





}



