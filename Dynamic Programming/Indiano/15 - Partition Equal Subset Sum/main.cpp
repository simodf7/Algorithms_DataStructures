#include <iostream>
#include <vector>
using namespace std; 

// You are given an array 'ARR' of 'N' positive integers. 
// Your task is to find if we can partition the given array into two subsets such that the sum of elements in both subsets is equal.

// For example, let’s say the given array is [2, 3, 3, 3, 4, 5], then the array can be partitioned as [2, 3, 5], and [3, 3, 4] with equal sum 10.

// Follow Up:

// Can you solve this using not more than O(S) extra space, where S is the sum of all elements of the given array?



// possiamo usare il codice del problema 13

int arr[6] = {2, 3, 3, 3, 4, 5}; 


int subset(int index, int target, vector<vector<int>> &dp){

    if(index == 0){
        return (arr[0] == target); 
    }

    if(target == 0){
        return true; 
    }

    if(dp[index][target] != -1){
        return dp[index][target]; 
    }

    bool take = false; 
    if(arr[index] <= target){
        take = subset(index-1, target - arr[index], dp); 
    }
    
    bool not_take = subset(index-1, target, dp); 

    dp[index][target] = take || not_take; 

    return dp[index][target]; 
}

int solve(){

    int dim = sizeof(arr)/sizeof(arr[0]); 
    if(dim % 2 != 0) return false;  

    int sum = 0; 
    for(int i=0; i<dim; i++){
        sum += arr[i]; 
    }


    int k = sum/2; 
    vector<vector<int>> dp(dim, vector<int>(k+1, -1)); 

    return subset(dim-1, sum/2, dp); 


}


int main(){

    if(solve()) {
        cout << "true" << endl; 
    } else cout << "false" << endl; 
    return 1; 
}