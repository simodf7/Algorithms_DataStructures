#include <stdio.h>
#include <stdlib.h>

// Incredibile funziona !!! pero secondo me è na latrin


int N=0; 
int H=0; 


// Function to swap two elements
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
// Partition function
int partition(int arr[], int low, int high)
{
 
    // initialize pivot to be the first element
    int pivot = arr[low];
    int i = low;
    int j = high;
 
    while (i < j) {
 
        // condition 1: find the first element greater than
        // the pivot (from starting)
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
 
        // condition 2: find the first element smaller than
        // the pivot (from last)
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}
 
// QuickSort function
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
 
        // call Partition function to find Partition Index
        int partitionIndex = partition(arr, low, high);
 
        // Recursively call quickSort() for left and right
        // half based on partition Index
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}
 
int isOkay(int *arr, int m, int hours){

    int i=0, bananas = arr[0]; 
    while(i<N){
        if(bananas <= m){
            i++;
            bananas = arr[i]; 

        }
        else{
            bananas -= m;      
        }
        hours--; 
    }

    if(hours>=0) return 1;

    return 0; 

}

int findMinimum(int *arr, int l, int r){
    
    int result = 0; 

    while(l<=r){
        int m = (r+l)/2; 

        if(isOkay(arr, m, H) == 1){
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
        fscanf(f, "%d", &H); 
        int piles[N]; 

        for(int i=0; i<N; i++){
            fscanf(f, "%d", &piles[i]); 
            // printf("%d ", piles[i]); 
        }

        // printf("\n"); 

        quickSort(piles, 0, N-1); 

        // for(int i=0; i<N; i++){
        //     printf("%d ", piles[i]); 
        // }

        // printf("\n"); 


        printf("Case# %d: %d \n", I, findMinimum(piles, piles[0], piles[N-1])); 
        I++; 

    }    


}



