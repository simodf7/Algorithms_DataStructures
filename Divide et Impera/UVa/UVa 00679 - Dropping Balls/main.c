#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int MAX_NODE; 


int BS(int nodo, int palle){

    int left = nodo*2; 
    int right = left +1; 
    if(left<MAX_NODE && right<MAX_NODE){
        if(palle%2 == 0) return BS(right, palle/2);
        else return BS(left, palle/2 +1);
    }
    else return nodo; 
}

int main(){

    FILE *f = NULL; 
    f = fopen("input.txt", "r"); 

    if(!f){
        printf("Error in opening file");
        return 0; 
    }
    

    int T,D,I; 
    fscanf(f, "%d", &T);
    while(T--){
        fscanf(f,"%d%d", &D, &I); 
        MAX_NODE = pow(2.0, D); 
        printf("%d\n", BS(1,I)); 
    }

    fclose(f);
    return 1; 

}