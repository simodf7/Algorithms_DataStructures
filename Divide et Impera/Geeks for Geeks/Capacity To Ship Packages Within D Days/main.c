#include <stdio.h>
#include <stdlib.h>

int N;
int D; 

// Anche qui ho dubbi sui limiti, va fatto un Quick sort??
// okay i limiti dovrebbero essere:
// lower bound = massimo (come lo trovo?)
// upper bound = somma dei valori

int isOkay(int *arr, int m, int days){

    int sum = 0; 
    int required_days = 1; 


    for(int i=0; i<N; i++){
        sum += arr[i];

        if(sum > m){
            required_days++; 
            sum = arr[i]; 
            if(i == N-1 && sum > m){
                required_days++;
            }
        }

        if(required_days > days){
            return 0;
        }

    }

    

    return 1; 
 
    

}

int findMinimum(int *arr, int l, int r){
    
    int result = 0; 

    while(l<=r){
        int m = (r+l)/2; 

        if(isOkay(arr, m, D) == 1){
            result = m; 
            r = m-1; 
        }
        else{
            l = m+1; 
        }

    }

    return result; 

}







int main(){

    FILE* f = NULL; 
    f = fopen("input.txt", "r"); 

    if(!f){
        printf("Error in opening file"); 
        return 0; 
    }


    int T, I=1; 

    fscanf(f, "%d", &T); 
    

    while(T--){
        fscanf(f, "%d", &N); 
        fscanf(f, "%d", &D); 
        
        printf("N: %d \n", N); 
        printf("D: %d \n", D); 

        int weights[N]; 

        for(int i=0; i<N; i++){
            fscanf(f, "%d", &weights[i]); 
            // printf("%d ", piles[i]); 
        }

        // printf("\n"); 

        // for(int i=0; i<N; i++){
        //     printf("%d ", piles[i]); 
        // }

        // printf("\n"); 



        // i limiti sono sbagliati 
        printf("Case# %d: %d \n", I, findMinimum(weights, 1, 20)); 
        I++; 
    }

}



