#include <iostream>
#include <vector>
using namespace std; 

// simile a Maximum sum ma primo e ultimo elemento non possono stare insieme

int a[4] = {2,1,4,9};  
vector<int> dp(4,-1); 

int maximumSum(int index, vector<int> a){


    if(index == 0) return a[index]; // se siamo arrivati a index = 0 lo prendiamo
    if(index <0) return 0; 

    // memoization

    if(dp[index] != -1){
        return dp[index]; 
    }

    // pick -- not pick 
    
    int pick = a[index] + maximumSum(index-2, a); // -2 perche non adiacenti
    int not_pick = 0 + maximumSum(index-1, a); // siccome non lo prendiamo andiamo al successivo

    dp[index] = max(pick, not_pick);
    return dp[index]; 
}

int main(){

    vector<int> temp1, temp2; 

    for(int i=0; i<4; i++){
        if(i != 0) temp1.push_back(a[i]); 
        if(i != 3) temp2.push_back(a[i]); 
    }

    cout << max(maximumSum(2, temp1), maximumSum(2,temp2)); 


}