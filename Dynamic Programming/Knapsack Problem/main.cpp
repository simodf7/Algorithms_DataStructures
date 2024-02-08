#include <iostream>
#include <vector>
using namespace std; 

// A thief is robbing a store and can carry a maximal weight of W into his knapsack. 
// There are N items and the ith item weighs wi and is of value vi. 
// Considering the constraints of the maximum weight that a knapsack can carry, 
// you have to find and return the maximum value that a thief can generate by stealing items.

int N,W; 
int weights[10];
int value[10];

int knapsack(int index, int w, vector<vector<int>>& dp){

    if(index == 0) return (w-weights[0]>=0) ? value[0] : 0; 

    if(dp[index][w] != -1) return dp[index][w]; 


    int take = -10000; 
    if(w-weights[index] >= 0){
        take = value[index] + knapsack(index-1, w-weights[index], dp); 
    }

    int not_take = knapsack(index-1, w, dp); 

    return dp[index][w] = max(take,not_take);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, i=1; 
    cin >> T; 

    while(T--){

        cin >> N; 

        for(int i=0; i<N; i++){
            cin >> weights[i];
        }

        for(int i=0; i<N; i++){
            cin >> value[i];
        }

        cin >> W; 

        vector<vector<int>> dp(N, vector<int>(W+1, -1));
        cout << "Case#" << i << ": " << knapsack(N-1, W, dp) << endl; 
        ++i;
    }


    return 1; 
}