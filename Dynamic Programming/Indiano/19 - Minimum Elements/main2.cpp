#include <iostream>
#include <vector>
using namespace std; 

// You are given an array of ‘N’ distinct integers and an integer ‘X’ representing the target sum.
// You have to tell the minimum number of elements you have to take to reach the target sum ‘X’.
// Note:

// You have an infinite number of elements of each type.

// For example

// If N=3 and X=7 and array elements are [1,2,3]. 
// Way 1 - You can take 4 elements  [2, 2, 2, 1] as 2 + 2 + 2 + 1 = 7.
// Way 2 - You can take 3 elements  [3, 3, 1] as 3 + 3 + 1 = 7.
// Here, you can see in Way 2 we have used 3 coins to reach the target sum of 7.
// Hence the output is 3.

int arr[3] = {1,2,5}; 
int N=3; 
int X=11; 

vector<vector<int>> dp(N, vector<int>(X+1, -1));

int minimumCoins(){

    for(int j=0; j<=X; j++){
        if(j % arr[0] == 0) dp[0][j] = j/arr[0];  
        else dp[0][j] = 10000; 
    }

    for(int i=1; i<N; i++){
        for(int j=0; j<=X; j++){

            int take = 10000; 
            if(j - arr[i] >= 0){
                take = 1 + dp[i][j-arr[i]]; 
            }
            int not_take = dp[i-1][j];  

            dp[i][j] = min(take, not_take); 

        }
    }


    // if(index < 0){
    //     return 10000; 
    // }

    return dp[N-1][X]; 
}


int main(){

    int d = minimumCoins(); 
    if(d != 10000) cout << d << endl; 
    else cout << -1 << endl; 

    return 1; 
}
