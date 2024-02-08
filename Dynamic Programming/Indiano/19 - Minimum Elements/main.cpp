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

vector<vector<int>> dp(3, vector<int>(12, -1));

int minimumCoins(int index, int target){

    // NON VA BENE PERCHE L'ULTIMO ELEMENTO POSSIAMO PRENDERLO PIU VOLTE
    // if(index < 0){  
    //     return 10000; 
    // }

    if(index == 0){
        if(target % arr[0] == 0) return target/arr[0]; 
        return 10000;
    }

    if(target == 0){
        return 0; 
    }
    
    if(dp[index][target] != -1) return dp[index][target]; 

    int take = 10000; 
    if(target - arr[index] >= 0){
        take = 1 + minimumCoins(index, target-arr[index]); 
    }
    int not_take = minimumCoins(index-1, target); 

    return dp[index][target] = min(take, not_take); 
}


int main(){

    int d = minimumCoins(N-1, X); 
    if(d != 10000) cout << minimumCoins(N-1, X) << endl; 
    else cout << -1 << endl; 

    return 1; 
}
