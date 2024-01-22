#include <iostream>
#include <vector>
using namespace std;

int arr[3] = {0,0,0}; 
 
void generaSequenzaGray(int n, int i, vector<int>& arr) {

    if (i == n) {
        for (int j = 0; j < n; j++) {
            cout << arr[j];
        }
        cout << endl;
        return;
    }
 
    // Non cambia il bit corrente
    generaSequenzaGray(n, i + 1, arr);
 
    // Cambia il bit corrente
    arr[i] = arr[i] ? 0 : 1; 
    generaSequenzaGray(n, i+1, arr); 
    
}
 
int main() {
    int n;
    cout << "Inserisci un numero tra 2 e 5: ";
    cin >> n;
 
    if (n < 2 || n > 5) {
        cout << "Numero non valido." << endl;
        return 1;
    }
 
    vector<int> arr(n, 0);
    generaSequenzaGray(n, 0, arr);
 
    return 0;
}
