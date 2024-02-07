#include <iostream>
#include <vector>

using namespace std; 

// You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. 
// Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.

// Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.
// For Example :

// If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. These are {1,3} and {4}. Hence, return true.

int arr[5] = {2,5,1,6,7};


bool isSubsetSum(int n, int k) {
    // Creare una tabella per memorizzare i risultati intermedi
    // La dimensione della tabella sarà (n+1) x (k+1)
    vector<vector<bool>> dp(n+1, vector<bool>(k+1, false));

    // Inizializzare la prima colonna come True, poiché la somma 0 è sempre possibile
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    // Riempire la tabella utilizzando l'approccio bottom-up
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {

            // Se l'elemento corrente è maggiore della somma attuale 'j',
            // quindi non possiamo includerlo e il risultato sarà lo stesso
            // di escludere questo elemento (preso dalla riga precedente)

            bool take = false; 

            if(arr[i-1] < j){
                take = dp[i-1][j-arr[i-1]]; 
            }

        
            // Altrimenti, verificare se è possibile ottenere la somma 'j'
            // includendo o escludendo l'elemento corrente
            bool not_take = dp[i-1][j];  

            dp[i][j] = take || not_take; 
        }
    }

    // Il risultato finale sarà nell'angolo in basso a destra della tabella
    return dp[n][k];
}

int main() {

    if (isSubsetSum(5, 4)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
