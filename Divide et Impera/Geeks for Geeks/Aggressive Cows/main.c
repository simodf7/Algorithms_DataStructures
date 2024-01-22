#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// okay
// sistemare i limiti
// lower bound = minimo
// upper bound = massimo

// il risultato su geeks for geeks mi sembra sbagliato


int K; 
int N;


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


int isValid(int *arr, int m, int cows){

	int distance = 0; 
	int placed_cows = 1; 

	for(int i=1; i<N; i++){
		distance += abs(arr[i] - arr[i-1]); 
		if(distance >= m){
			placed_cows++; 
			distance = 0; 
		}

		if(placed_cows == cows){
			return 1;  // good
		}
	}

	

	return 0; 


}

int solve(int stalls[], int l, int r){

    //quickSort(stalls, 0, N-1); 
	
	int result = 0; 

    while(l<=r){
        int m = (r+l)/2; 

        if(isValid(stalls, m, K) == 1){
            result = m; 
            // r= m-1; 
			l = m+1;
        }
        else{
			r = m-1; 
			// l = m+1; 
            
        }

    }

    return result; 



}








int main(){

    FILE *f = NULL; 
    f = fopen("input.txt", "r"); 

    if(!f){
        printf("Error in opening file");
        return 0; 
    }

    int T, I=1;  

    fscanf(f, "%d", &T); 
    while(T--){
        fscanf(f, "%d", &N);
        fscanf(f, "%d", &K);
        int stalls[N]; 
        
        for(int i=0; i<N; i++){
            fscanf(f, "%d", &stalls[i]); 
        }

		
        printf("Case# %d: %d \n", I, solve(stalls, 1, 20)); 
        I++;
    }
    

    fclose(f); 
    return 1; 




}


