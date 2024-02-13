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

int palindrom() {
    
    int n = s.size(); 

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                dp[i][j] = 1;
            } else if (s[i] == s[j]) {
                dp[i][j] = 2 + (i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0);
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[0][n - 1];
}


int main(){

    cout << palindrom();  

}