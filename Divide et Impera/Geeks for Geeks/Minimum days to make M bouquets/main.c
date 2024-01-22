#include <stdio.h>
#include <stdlib.h>

// da completare

int isValid;

int findMinimum(int *arr, int M, int K, int N){




}


int main(){

    FILE* f = NULL; 
    f = fopen("input.txt", "r"); 

    if(!f){
        printf("Error in opening file"); 
        return 0; 
    }


    int T, I=1, M, K, N; 

    fscanf(f, "%d", &T); 

    while(T--){
        fscanf(f, "%d", &M); 
        fscanf(f, "%d", &K); 
        fscanf(f, "%d", &N);  
        int bloomday[N]; 

        for(int i=0; i<N; i++){
            fscanf(f, "%d", &bloomday[i]); 
            // printf("%d ", piles[i]); 
        }

        // printf("\n"); 

        quickSort(bloomday, 0, N-1); 

        // for(int i=0; i<N; i++){
        //     printf("%d ", piles[i]); 
        // }

        // printf("\n"); 


        // printf("Case# %d: %d \n", I, findMinimum(, piles[0], piles[N-1])); 
        I++; 

    }    


}



