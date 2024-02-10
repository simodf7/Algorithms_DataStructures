#include <iostream>
#include <vector>
using namespace std; 

string text1 = "ace";
string text2 = "cde";

vector<vector<string>> dp(text1.size()+1, vector<string>(text2.size()+1, "")); 

string LCS(int index1, int index2){

    if(index1 < 0 || index2 < 0){
        return ""; 
    }


    if(text1[index1] == text2[index2]){
        return dp[index1][index2] = LCS(index1-1, index2-1) + text1[index1]; 
    }

    string s1 = LCS(index1-1, index2); 
    string s2 = LCS(index1, index2-1); 


    return dp[index1][index2] = (s1.length() > s2.length()) ? s1: s2; 
}


int main(){

    cout << LCS(text1.size()-1, text2.size()-1) << endl; 
    return 1; 
}