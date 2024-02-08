#include <iostream> 
#include <vector>
using namespace std; 


// You are given an array 'arr' containing 'n' non-negative integers.


// Your task is to partition this array into two subsets such that the absolute difference between subset sums is minimum.


// You just need to find the minimum absolute difference considering any valid division of the array elements.


// Note:

// 1. Each array element should belong to exactly one of the subsets.

// 2. Subsets need not always be contiguous.
// For example, for the array : [1, 2, 3], some of the possible divisions are 
//    a) {1,2} and {3}
//    b) {1,3} and {2}.

// 3. Subset-sum is the sum of all the elements in that subset. 

// Example:

// Input: 'n' = 5, 'arr' = [3, 1, 5, 2, 8].

// Ouput: 1

// Explanation: We can partition the given array into {3, 1, 5} and {2, 8}. 
// This will give us the minimum possible absolute difference i.e. (10 - 9 = 1).


int arr[5] = {3, 1, 5, 2, 8};


bool minimum() {
    // Creare una tabella per memorizzare i risultati intermedi
    // La dimensione della tabella sarà (n+1) x (k+1)

    int k = 0;    
    for(int i = 0; i<5; i++){
        k += arr[i]; 
    }

    int n = sizeof(arr)/sizeof(arr[0]); 

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

    // // Il risultato finale sarà nell'angolo in basso a destra della tabella
    // return dp[n][k];


    int minim = 10000; 
    for(int i=0; i<=k; i++){
        if(dp[n-1][k] == true){
            int diff = abs(i-(k-i)); 
            minim = min(minim, diff); 
        }
    }

    return minim; 
    
}

int main() {

    cout << minimum() << endl;

    return 0;
}
