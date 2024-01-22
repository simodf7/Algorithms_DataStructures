#include <stdio.h>
#include <stdlib.h>

int diff; 

// int trova_numero(int num[], int n, int totale){
//     // sei una latrina
//     if(n==0){
//         return S-totale; 
//     }
//     else{
//         return trova_numero(num, n-1, totale + num[n-1]); 
//     }



// }


int trova_numero(int num[], int l, int r){

    if(l>=r){
        return -1; 
    }

    int m = l + (r-l)/2; 


    if(num[m] - num[m-1] != diff){
        return num[m-1] + diff;  
    }
    
    
    if(num[m+1] - num[m] != diff){
        return num[m] + diff; 
    }


    if(num[m] == num[0] + m*diff){
        return trova_numero(num, m, r); 
    }
    
    return trova_numero(num, l, m-1); 

}



int main(){

    FILE *f = NULL; 
    f = fopen("input.txt", "r"); 

    if(!f){
        printf("Error in opening file");
        return 0; 
    }

    int T, N, I=1; 
    fscanf(f, "%d", &T); 
    
    while(T--){
        fscanf(f, "%d", &N);

        int num[N]; 
        for(int i=0; i<N; i++){
           fscanf(f, "%d", &num[i]);  
        }

        diff = (num[N-1] - num[0])/N;  

        printf("Case# %d: \n", I); 
        I++;
        printf("%d\n", trova_numero(num, 0, N));
        
    }
    

    fclose(f); 
    return 1; 



}