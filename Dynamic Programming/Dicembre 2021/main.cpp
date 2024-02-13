#include <iostream>
#include <vector>
using namespace std; 


// Il palindromo è una sequenza di caratteri che, letta al contrario, rimane invariata. Ad esempio, GAG
// e MADAM sono palindromi, ma ADAM no. Assumiamo che anche la stringa vuota sia un palindromo.
// Da qualsiasi stringa non palindromica, si può sempre ottenere una sotto-sequenza palindromica
// togliendo alcune lettere: ad esempio, data la stringa ADAM, si può rimuovere la lettera M e ottenere
// ADA. Scrivere un programma per determinare la lunghezza del palindromo più lungo che puoi
// ottenere da una stringa rimuovendo zero o più caratteri.

// ADAM = 3
// MADAM = 5

string s = "MADAM"; 

vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1)); 

int palindrom(int i, int j){

    if(i>=j) return 1; 

    if(dp[i][j] != -1) return dp[i][j]; 

    if(s[i] == s[j]){
        return dp[i][j] = 2 + palindrom(i+1,j-1); 
    }

    return dp[i][j] = max(palindrom(i+1, j), palindrom(i, j-1));

}


int main(){

    cout << palindrom(0, s.size()-1);  

}