#include <iostream>
#include <vector>
using namespace std; 

int a[4] = {2,1,4,9};  
vector<int> dp(4,0); 

int maximumSum(int index){

    // tabulation

    dp[0] = a[0]; 
   
    int pick, not_pick; 

    for(int i=1; i<=index; i++){
        pick = a[i]; 
        if(i>1) pick += dp[i-2]; // -2 perche non adiacenti
        not_pick = 0 + dp[i-1]; // siccome non lo prendiamo andiamo al successivo
        dp[i] = max(pick, not_pick); 
    }

    return dp[index]; 
    
}

int main(){

    cout << maximumSum(3); 

    return 1; 
}