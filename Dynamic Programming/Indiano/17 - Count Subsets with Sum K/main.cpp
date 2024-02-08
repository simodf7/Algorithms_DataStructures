#include <iostream>
#include <vector>
using namespace std; 


// You are given an array 'arr' of size 'n' containing positive integers and a target sum 'k'.
// Find the number of ways of selecting the elements from the array such that the sum of chosen elements is equal to the target 'k'.
// Since the number of ways can be very large, print it modulo 10 ^ 9 + 7.

// Example:

// Input: 'arr' = [1, 1, 4, 5]

// Output: 3

// Explanation: The possible ways are:
// [1, 4]
// [1, 4]
// [5]
// Hence the output will be 3. Please note that both 1 present in 'arr' are treated differently.


int arr[4] = {1, 1, 4, 5}; 
vector<vector<int>> dp(4, vector<int>(6, -1));

int countSubset(int index, int target){

    if(target == 0){
        return 1; 
    }

    if(index == 0){
        if(target == arr[0]){
            return 1; 
        }
        return 0; 
    }

    if(dp[index][target] != -1){
        return dp[index][target];
    }

   
    int take = 0; 

    if(target >= arr[index] ){
        take = countSubset(index-1, target - arr[index]) ; 
    }
    int not_take = countSubset(index-1, target) ; 


    return dp[index][target] = take + not_take; 
}




int main(){ 

    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << countSubset(n-1, 5) << endl; 
    return 1; 
}




