#include <iostream>
#include <vector>
using namespace std; 

// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

//     Insert a character
//     Delete a character
//     Replace a character


string s1 = "horse"; 
string s2 = "ros"; 

vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0)); 

int editDistance(){



    for(int i=0; i<=s1.size(); i++){
        dp[i][0] = i;  // occhio allo shifting ora e' i e non i+1
    }

    for(int j=0; j<=s2.size(); j++){
        dp[0][j] = j; 
    }


    for(int i=1; i<=s1.size(); i++){
        for(int j=1; j<=s2.size(); j++){

            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];  
            }
            else{
                 // insert house(s) ros = inserisco s cosi da fare il matching e shifto j
                int insert = 1 + dp[i][j-1];  
                // cancello la e di house e shifto i
                int deletion = 1 + dp[i-1][j]; 
                // sostituisco la e con la s e quindi shifto entrambi perche ho matchato
                int replace = 1 + dp[i-1][j-1]; 


                dp[i][j] = min(insert, min(deletion, replace)); 
            }

           
        }
    }

    return dp[s1.size()][s2.size()]; 
    
}


int main(){

    cout << editDistance() << endl; 
    return 1; 
}