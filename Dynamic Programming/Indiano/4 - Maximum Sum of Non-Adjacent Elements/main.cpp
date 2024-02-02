#include <iostream>
#include <vector>
using namespace std; 

int a[4] = {2,1,4,9};  
vector<int> dp(4,-1); 

int maximumSum(int index){


    if(index == 0) return a[index]; // se siamo arrivati a index = 0 lo prendiamo
    if(index <0) return 0; 

    // memoization

    if(dp[index] != -1){
        return dp[index]; 
    }

    // pick -- not pick 
    
    int pick = a[index] + maximumSum(index-2); // -2 perche non adiacenti
    int not_pick = 0 + maximumSum(index-1); // siccome non lo prendiamo andiamo al successivo

    dp[index] = max(pick, not_pick);
    return dp[index]; 
}

int main(){

    cout << maximumSum(3); 

    return 1; 
}