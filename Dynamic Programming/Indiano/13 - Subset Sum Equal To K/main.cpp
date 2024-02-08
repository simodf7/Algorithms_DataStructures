#include <iostream>
#include <vector>

using namespace std; 

// You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. 
// Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.

// Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.
// For Example :

// If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. These are {1,3} and {4}. Hence, return true.

int arr[4] = {1,2,3,4};
vector<vector<int>> dp(4, vector<int>(5, -1)); 


int subset(int index, int target){

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
        take = subset(index-1, target - arr[index]); 
    }
    
    bool not_take = subset(index-1, target); 

    dp[index][target] = take || not_take; 

    return dp[index][target]; 
}


int main(){

    if(subset(3, 4)) {
        cout << "true" << endl; 
    } else cout << "false" << endl; 
 
    return 1; 
}