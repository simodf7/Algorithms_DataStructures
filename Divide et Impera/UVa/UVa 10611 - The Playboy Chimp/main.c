#include <stdio.h>
#include <stdlib.h>


int shortest_one_taller(int chimps[], int height, int l, int r){

    if(l>r){
        return l; 
    }

    int m = l + (r-l)/2; 


    if(chimps[m] <= height){
        return shortest_one_taller(chimps, height, l, m-1); 
    }

    if(chimps[m] > height){
        return shortest_one_taller(chimps, height, m+1, r); 
    }


}


int main(){

    FILE *f = NULL; 
    f = fopen("input.txt", "r"); 

    if(!f){
        printf("Error in opening file");
        return 0; 
    }

    int H, N, Q, I=1; 

    fscanf(f, "%d", &N); 
    int chimps[N];

    for(int i=0; i<N; i++){
        fscanf(f, "%d", &chimps[i]);
        printf("%d ", chimps[i]);
    }

    fscanf(f, "%d", &Q); 
    printf("\n"); 

    while(Q--){
        fscanf(f, "%d", &H); 
        printf("%d ", H);
        printf("Case# %d: %d \n", I, chimps[shortest_one_taller(chimps,H, 0, N-1)]); 
        I++;
    }
   

    fclose(f); 
    return 1; 


}