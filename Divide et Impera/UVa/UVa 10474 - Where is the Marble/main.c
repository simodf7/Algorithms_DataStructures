#include <stdio.h>
#include <stdlib.h>


int value_query; 


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




int BS(int arr[], int m, int n){

    if(m <= n){
       int q =  m + (n - m) / 2; 

        if (arr[q] == value_query) return q; 
        else if (value_query < q) return BS(arr, m, q-1); 
        else return BS(arr, q+1, n); 
    }
    
    return -1; 

}

int main(){

    FILE *f = NULL; 
    f = fopen("input.txt", "r"); 

    if(!f){
        printf("Error in opening file");
        return 0; 
    }
    

    int M, V, Q, T = 1; 
    
    fscanf(f, "%d", &M); 
    fscanf(f, "%d", &Q); 

    do{
    
        int marbles[M];    

        for(int i=0; i<M; i++){
            fscanf(f, "%d", &marbles[i]); 
        }

        printf("Case# %d: \n", T);

        quickSort(marbles, 0, M-1); 
        for(int i=0; i<Q; i++){
            fscanf(f, "%d", &value_query);
            int res = BS(marbles, 0, M); 
            if(res != -1) printf("%d found at %d \n", value_query, res+1);
            else printf("%d not found \n", value_query); 
        }

        
        T++; 

        fscanf(f, "%d", &M); 
        fscanf(f, "%d", &Q); 

    } while(M != 0 && value_query != 0);
    
    fclose(f);
    return 1; 

}


