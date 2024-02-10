#include <iostream>
#include <vector>
using namespace std; 


string text1 = "abcde";
string text2 = "ace"; 

vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1)); 


int LCS(int index1, int index2){


    if(index1 <0 || index2 <0){
        return 0; 
    }

    if(dp[index1][index2] != -1) return dp[index1][index2]; 
    
    if(text1[index1] == text2[index2]){
        return dp[index1][index2] =  1 + LCS(index1-1, index2-1); 
    }

    return dp[index1][index2] = max(LCS(index1-1, index2), LCS(index1, index2-1)); 

}


int main(){

    cout << LCS(text1.size()-1, text2.size()-1) << endl; 
    return 1;  
}