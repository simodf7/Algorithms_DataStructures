#include <stdio.h>
#include <stdlib.h>

int max_triangle_height(int N, int height) {
    
    int coins = (height*(height + 1))/2; 

    if(N == coins) return height;
    else if (N > coins) return max_triangle_height(N, height+1); 
    else return height-1;
}


int main(){

    FILE *f = NULL; 
    f = fopen("input.txt", "r"); 

    if(!f){
        printf("Error in opening file");
        return 0; 
    }

    int T, V, I=1; 

    fscanf(f, "%d", &T); 
    while(T--){
        fscanf(f, "%d", &V); 
        printf("Case# %d: %d \n", I, max_triangle_height(V, 1)); 
        I++;
    }
    

    fclose(f); 
    return 1; 


}