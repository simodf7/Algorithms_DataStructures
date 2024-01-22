#include <iostream>

using namespace std; 


void merge(int arr[], int p, int m, int r){

    


}; 

void mergeSort(int arr[], int p, int r){

    if(p>=r){
        return; 
    }
    
    int m = (p+r)/2; 

    mergeSort(arr, p, m); 
    mergeSort(arr, m+1, r); 
    merge(arr, p, m, r); 
}

int main(){


}