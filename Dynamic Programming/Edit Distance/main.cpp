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

vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1)); 


int editDistance(int index1, int index2){

    // attenzione ai casi base
    
    // se index1 < 0, vuol dire che s1 è stringa vuota e devo trasformarla in s2 che ha j+1 caratteri 
    // quindi devo fare j+1 insert
    if(index1<0) return index2+1; 

    // se index2 < 0, vuol dire che s2 è stringa vuota e devo trasformare s1 in "" 
    // quindi devo fare i+1 delete
    if(index2<0) return index1+1; 

    if(dp[index1][index2] != -1) return dp[index1][index2]; 


    if(s1[index1] == s2[index2]){
        return dp[index1][index2] = editDistance(index1-1, index2-1); 
    }

    // insert house(s) ros = inserisco s cosi da fare il matching e shifto j
    int insert = 1 + editDistance(index1, index2-1); 
    // cancello la e di house e shifto i
    int deletion = 1 + editDistance(index1-1, index2); 
    // sostituisco la e con la s e quindi shifto entrambi perche ho matchato
    int replace = 1 + editDistance(index1-1, index2-1); 


    return dp[index1][index2] = min(insert, min(deletion, replace)); 
}


int main(){

    cout << editDistance(s1.size()-1, s2.size()-1) << endl; 
    return 1; 
}