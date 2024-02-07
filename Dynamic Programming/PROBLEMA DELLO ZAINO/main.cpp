#include <iostream>
#include <vector>
using namespace std; 

// You are given ‘n’ items with certain ‘profit’ and ‘weight’ and a knapsack with weight capacity ‘w’.

// You need to fill the knapsack with the items in such a way that you get the maximum profit. You are allowed to take one item multiple times.
// Example:

// Input: 
// 'n' = 3, 'w' = 10, 
// 'profit' = [5, 11, 13]
// 'weight' = [2, 4, 6]

// Output: 27

// Explanation:
// We can fill the knapsack as:

// 1 item of weight 6 and 1 item of weight 4.
// 1 item of weight 6 and 2 items of weight 2.
// 2 items of weight 4 and 1 item of weight 2.
// 5 items of weight 2.

// The maximum profit will be from case 3 = 11 + 11 + 5 = 27. Therefore maximum profit = 27.
 
int profit[3] = {5, 11, 13}; 
int weight[3] = {2, 4, 6}; 

// int profit[2] = {6, 12}; 
// int weight[2] = {4,17};

vector<vector<int>> dp(3, vector<int>(11, -1)); 

int knapsack(int index, int w){


    if(index == 0){
        if(w-weight[0] >= 0){
            return profit[index];
        }
        return 0;
    }

    if(dp[index][w] != -1){
        return dp[index][w]; 
    }

    int take = -10000; 

    if(weight[index] <= w){
        take = profit[index] + knapsack(index, w - weight[index]); 
    }

    int not_take = knapsack(index-1, w); 

    dp[index][w] = max(take, not_take);
    return dp[index][w];

}

int main(){

    cout << knapsack(2, 10) << endl; 
    return 1; 


}