#include <iostream>
#include <vector>

using namespace std;

int height[6] = {30,10,60,10,60,50}; 
// vector<int> dp(6,-1); // memoization top-down
vector<int> dp(6,0); // tabulation bottom-up

int calls = 0;

int minimalEnergy_noDP(int n){
    
    calls++; 

    if(n==0){
        return 0; 
    }
 
    // salto di 1
    int one_step_energy = minimalEnergy_noDP(n-1) + abs(height[n] - height[n-1]); 
    int two_steps_energy = 10000; 
    if(n>1) { // un salto di 2 non è sempre possibile
        two_steps_energy = minimalEnergy_noDP(n-2) + abs(height[n] - height[n-2]); 
    }

    return min(one_step_energy, two_steps_energy); 
}


int minimalEnergy(int n){

    calls++; 
    
    if(n==0){
        return 0; 
    }

    if(dp[n] != -1){  // memoization
        return dp[n]; 
    }
 
    // salto di 1
    int one_step_energy = minimalEnergy(n-1) + abs(height[n] - height[n-1]); 
    int two_steps_energy = 10000; 
    if(n>1) { // un salto di 2 non è sempre possibile
        two_steps_energy = minimalEnergy(n-2) + abs(height[n] - height[n-2]); 
    }

    dp[n] = min(one_step_energy, two_steps_energy); 
    return dp[n]; 
}


int minimalEnergy_TAB(int n){  //tabulation

    calls++; 
    
    dp[0] = 0; 

    for(int i=1; i<=n; i++){
        int os = dp[i-1] + abs(height[i] - height[i-1]); 
        int ts = 10000; 
        if(i>1){
            ts = dp[i-2] + abs(height[i] - height[i-2]); 
        }

        dp[i] = min(os, ts); 
    }
 
    return dp[n]; 
}



int main(){

    // cout << minimalEnergy_noDP(5) << " with calls: " << calls << endl;
    // calls = 0;  
    // cout << minimalEnergy(5) << " Memoization with calls: " << calls << endl;
    // calls = 0;  
    cout << minimalEnergy_TAB(5) << " Tabulation with calls: " << calls << endl;
    return 1; 
}