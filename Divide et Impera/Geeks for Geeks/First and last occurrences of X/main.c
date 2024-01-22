#include <stdio.h>
#include <stdlib.h>

int firstOccurence(int *arr, int l, int r, int x){
    
    int res = -1; 

    while(l <= r){

        int m = (l+r)/2; 

        if(arr[m] == x){
            res = m; 
            r = m-1; // left
        }
        else if(arr[m] < x){
            l = m +1;  // right
        }
        else{
            r = m-1;  // left
        }


    }

    return res; 
}


int lastOccurence(int *arr, int l, int r, int x){
    
    int res = -1; 

    while(l <= r){

        int m = (l+r)/2; 

        if(arr[m] == x){
            res = m; 
            l = m+1; // right 
        }
        else if(arr[m] < x){
            l = m +1; //right
        }
        else{
            r = m-1; // left
        }


    }

    return res; 
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

        printf("Case# %d: %d %d \n", I, firstOccurence(values, 0, N-1, X), lastOccurence(values, 0, N-1, X)); 
        I++; 

    }    


}



