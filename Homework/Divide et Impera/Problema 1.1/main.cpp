#include <iostream>
#include <vector>

using namespace std;


// Si richiede di analizzare un particolare algoritmo di ordinamento. L'algoritmo elabora una
// sequenza di n interi distinti scambiando due elementi adiacenti finché la sequenza non viene
// ordinata in ordine crescente. La lunghezza massima della sequenza di input è n < 500.000.
// Per la sequenza di input: 91054, l’algoritmo produce l'output 01459.
// Bisogna determinare quante operazioni di scambio sono necessarie a quest’algoritmo per
// ordinare una determinata sequenza di input.
// Un modo alternativo di vedere è il problema è in termini di “inversioni”: in una sequenza A,
// la coppia (i, j) è un’inversione se i < j e Ai > Aj. Il problema consiste nel trovare il conteggio
// delle inversioni.

int mergeCount(vector<int>& V, int p, int q, int r) {
    vector<int> V2(r - p + 1);
    int i = p, j = q + 1, k = 0;
    int ans = 0;

    while (i <= q && j <= r) {
        if (V[i] <= V[j]) {
            V2[k++] = V[i++];
        } else {
            ans += (q - i + 1);   // [2 3 5 6] [2 2 4 4 8]  se 3>2 quindi coppia, saranno coppie anche 5 2 e 6 2 perche i vettori sono ordinati
            V2[k++] = V[j++];
        }
    }

    while (i <= q) {
        V2[k++] = V[i++];
    }

    while (j <= r) {
        V2[k++] = V[j++];
    }

    for (int i = p; i <= r; i++) {
        V[i] = V2[i - p];
    }

    return ans;
}

int mergeSort(vector<int>& V, int p, int r) {
    int ans = 0;
    if (p < r) {
        int q =(r + p) / 2;
        ans += mergeSort(V, p, q);
        ans += mergeSort(V, q + 1, r);
        ans += mergeCount(V, p, q, r);
    }
    return ans;
}



int main(){
ios::sync_with_stdio(0);
cin.tie(0);
int n, x, ans=0, j = 1;

    while(cin>>n){

        if(n == 0) break;

        vector <int> V (n);

        for (int i = 0; i<n; i++){
            cin>>x;
            V[i] = x;
        }

        int ans = mergeSort(V, 0, n-1);
        cout<<"Test Case #"<<j<<": "<<ans<<"\n";
        j++;
        ans = 0;
    }
}