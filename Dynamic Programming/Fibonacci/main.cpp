#include <iostream>
#include <vector>
using namespace std; 


vector<int> dp(20, -1); 

int fibonacci(int n){

    if(n <= 1){
        return n; 
    }

    if(dp[n] != -1){ // memoization 
        return dp[n]; 
    }


    dp[n] = fibonacci(n-1) + fibonacci(n-2);
    return dp[n]; 

}


int main(){


    cout << "Fibonacci: " << fibonacci(3) << endl; 

    return 1; 
}