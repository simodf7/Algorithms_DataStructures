#include <iostream>
#include <vector>

using namespace std;
vector<int> dp (20, -1); 


int countWays(int n){
    
    if(n<=1){
        return 1; 
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int one_step = countWays(n-1); 
    int two_steps = countWays(n-2); 

    dp[n] = one_step + two_steps;  
    return dp[n]; 
 
}


int main(){

    cout << countWays(3); 


    return 1; 
}