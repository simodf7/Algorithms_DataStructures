#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define M 30



int checkDifference(int values[], int m){

    if(abs(values[m-1] - values[m+1]) == 1 ||  abs(values[m-1] - values[m+1]) == 0){ 
        return 1; 
    }

    return 0; 

}


int isJolly(int values[], int l, int r){

    if(r-l == 1){
        return 1; 
    }

    int m = l + (r-l)/2; 


    if(checkDifference(values, m) == 1 && m>0){ 
        int left = isJolly(values, 0, m); 
        int right = isJolly(values, m, r); 
        if (left == 1 && right == 1) return 1;
    }

    return 0; 
    

}




int main() {
    FILE *file = fopen("input.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char buffer[100];
    int values[M];
    int T=1, N=0; 
    

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Tokenize the line based on spaces
        char *token = strtok(buffer, " ");
        
        // Process each token (integer value)
        while (token != NULL && N < M) {
            // Convert the token to an integer and store in the array
            values[N] = atoi(token);
            N++; 
            // Get the next token
            token = strtok(NULL, " ");
        }
        

        int result = isJolly(values, 0, N-1); 

        if(result){
            printf("Case# %d: %s \n", T, "Jolly"); 
        }else{
            printf("Case# %d: %s \n", T, "Not Jolly"); 
        }
        

        N = 0; 
        T++; 

    }

    

    fclose(file);

    return 0;
}