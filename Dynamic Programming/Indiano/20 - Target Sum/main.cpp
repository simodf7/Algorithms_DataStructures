#include <iostream>
#include <vector>
using namespace std;

// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

//     For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".

// Return the number of different expressions that you can build, which evaluates to target.

// Example 1:

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3

int nums[5] = {1,1,1,1,1}; 
int N = 5; 
int T = 3; 

vector<int> dp(N, -1);

// ????

int targetSum(int index, int sum){

    if(index<0) {
        if(sum == T) return 1; 
        return 0; 
    }

    if(dp[index] != -1) return dp[index];


    int plus = targetSum(index-1, sum + nums[index]); 
    int minus = targetSum(index-1, sum - nums[index]); 


    return dp[index] = plus + minus; 
}


int main(){

    cout << targetSum(N-1, T) << endl; 

    return 1; 
}