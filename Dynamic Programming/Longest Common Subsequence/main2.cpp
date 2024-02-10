#include <iostream>
#include <vector>
using namespace std; 


string text1 = "abcde";
string text2 = "ace"; 

vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0)); 


int LCS(){

    //shifting index -1 0 ... n-1 -> 0 1 ... n

    for(int j=0; j<text2.size(); j++){
        dp[0][j] = 0;  // sarebbe j-1
    }

    for(int i=0; i<text1.size(); i++){
        dp[i][0] = 0;  // sarebbe i-1
    }

    for(int i=1; i<=text1.size(); i++){
        for(int j=1; j<=text2.size(); j++){

            if(text1[i-1] == text2[j-1]){
                dp[i][j] =  1 + dp[i-1][j-1]; 
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }

        }

    }

    return dp[text1.size()][text2.size()];  // il risultato non e' piu in n-1 m-1 ma in n m
    
    
}


int main(){

    cout << LCS() << endl;
    return 1;  
}