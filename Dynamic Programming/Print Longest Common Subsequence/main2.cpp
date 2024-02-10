#include <iostream>
#include <vector>
using namespace std; 

string text1 = "ace";
string text2 = "cde";

vector<vector<string>> dp(text1.size()+1, vector<string>(text2.size()+1, "")); 

string LCS(){


    for(int i=0; i<text1.size(); i++){
        dp[i][0] = ""; 
    }

    for(int j=0; j<text2.size(); j++){
        dp[0][j] = ""; 
    }


    for(int i=1; i<=text1.size(); i++){
        for(int j=1; j<=text2.size(); j++){

            if(text1[i-1] == text2[j-1]){
                dp[i][j] = dp[i-1][j-1] + text1[i-1]; 
            }
            else{
                string s1 = dp[i-1][j];
                string s2 = dp[i][j-1]; 


                dp[i][j] = (s1.length() > s2.length()) ? s1: s2;
            }
            

        }
    }

    return dp[text1.size()][text2.size()]; 
    
}


int main(){

    cout << LCS() << endl; 
    return 1; 
}