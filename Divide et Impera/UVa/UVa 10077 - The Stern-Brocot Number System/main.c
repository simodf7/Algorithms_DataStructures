#include <stdio.h>
#include <stdlib.h>





int main(){

    FILE *f = NULL; 
    f = fopen("input.txt", "r"); 

    

    if(!f){
        printf("Error in opening file");
        return 0; 
    }
    


    fclose(f);
    return 1; 
}