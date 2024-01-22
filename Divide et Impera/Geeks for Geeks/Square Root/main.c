#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int squareRoot(double v, int l, int r){
    
    if (l>r){
        return r; 
    }
    
    int m = (l+r)/2; 

    if(pow(1.0*m, 2) == v){
        return m; 
    }
    else if(pow(1.0*m, 2) < v){
        return squareRoot(v, m+1, r); 
    }
    else{
        return squareRoot(v, l, m-1); 
    }

}





int main(){

    FILE* f = NULL; 
    f = fopen("input.txt", "r"); 

    if(!f){
        printf("Error in opening file"); 
        return 0; 
    }


    int T, I=1;
    double V; 

    fscanf(f, "%d", &T); 

    while(T--){
        fscanf(f, "%lf", &V);  

        printf("Case# %d: %d \n", I, squareRoot(V, 0, V-1)); 
        I++; 

    }    


}



