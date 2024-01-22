#include <stdio.h>
#include <stdlib.h>

int N;
int K; 

// va fatto un Quick sort??

int sum(int *arr, int m){

    int res = 0; 

    for(int i=0; i<N; i++){
        
        if(arr[i] % m == 0){
            res += (arr[i] / m); 
        }
        else{
            res += (arr[i]/m  +1);  
        }
    }

    return res; 

}

int findMinimum(int *arr, int l, int r){
    
    int index = 0; 

    while(l<=r){
        int m = (r+l)/2; 

        if(sum(arr, m) <= K){
            index = m; 
            r = m-1; 
        }
        else{
            l = m+1; 
        }

    }

    return index; 

}







int main(){

    FILE* f = NULL; 
    f = fopen("input.txt", "r"); 

    if(!f){
        printf("Error in opening file"); 
        return 0; 
    }


    // int T, I=1; 

    // fscanf(f, "%d", &T); 
    
    fscanf(f, "%d", &K); 
    fscanf(f, "%d", &N); 
     
    int numbers[N]; 

    for(int i=0; i<N; i++){
        fscanf(f, "%d", &numbers[i]); 
        // printf("%d ", piles[i]); 
    }

    // printf("\n"); 

    // for(int i=0; i<N; i++){
    //     printf("%d ", piles[i]); 
    // }

    // printf("\n"); 


    printf("Case#: %d \n", findMinimum(numbers, 1, 200)); 
    // I++; 


}



