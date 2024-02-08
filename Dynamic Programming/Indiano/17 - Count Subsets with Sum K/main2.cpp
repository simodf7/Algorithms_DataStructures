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
vector<vector<int>> dp(4, vector<int>(6, 0));

int countSubset(){


    for(int i=0; i<4; i++){
        dp[i][0] = 1; 
    }

    if(arr[0] <= 5){
        dp[0][arr[0]] = 1; 
    }

    for(int i=1; i<4; i++){
        for(int j=1; j<=5; j++){

            int take = 0; 

            if(j >= arr[i] ){
                take = dp[i-1][j-arr[i]]; 
            }
            int not_take = dp[i-1][j]; 

            dp[i][j] = take + not_take; 

        }
    }
   
    return dp[3][5];  
}




int main(){ 

    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << countSubset() << endl; 
    return 1; 
}




