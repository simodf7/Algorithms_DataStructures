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

int knapsack(vector<vector<int>>& dp){

    for(int j=0; j<=W; j++){
        if(j-weights[0] >=0){
            dp[0][j] = value[0];
        } else dp[0][j] = 0; 
    }


    for(int i=1; i<N; i++){
        for(int j=1; j<=W; j++){

            int take = -10000; 
            if(j-weights[i] >= 0){
                take = value[i] + dp[i-1][j-weights[i]];
            }

            int not_take = dp[i-1][j];  

            dp[i][j] = max(take,not_take);
        }
    }


    return dp[N-1][W]; 
    
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
        cout << "Case#" << i << ": " << knapsack(dp) << endl; 
        ++i;
    }


    return 1; 
}