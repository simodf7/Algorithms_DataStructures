#include <iostream>
#include <vector>
using namespace std; 

// Si supponga di avere N classi di prodotti, e dobbiamo acquistare un solo prodotto per ogni classe.
// Si supponga di disporre di un budget B, e di voler spendere la massimo quantità possibile (<= B) per
// acquistare un solo prodotto per classe.
// Si scriva un algoritmo che calcoli la massima quantità di denaro, minore o uguale ad B, che
// spendiamo per acquistare un prodotto per ogni classe. Nota: è possibile che il budget B non sia
// sufficiente ad acquistare un prodotto per ogni classe; in tal caso il programma stampi “denaro
// insufficiente”.


int budget = 100; 
int n_classes = 4;



vector<vector<int>> classes = {
    {8, 6, 4},
    {5,10},
    {1, 3, 3, 7},
    {50, 14, 23, 8}
}; 

vector<vector<int>> dp(n_classes+1, vector<int>(budget+1, -1)); 

int f(){

    for(int j=0; j<=budget; j++){
        dp[n_classes][j] = 0; 
    }

    for(int i=n_classes-1; i>=0; i--){ // 3 0 // 
        for(int j=0; j<=budget; j++){

            int spending = -1000; 
            for(int k=0; k<classes[i].size(); k++){
                if(classes[i][k] <= j){
                    spending = max(spending, classes[i][k] + dp[i+1][j-classes[i][k]]); 
                }
            }

            dp[i][j] = spending; 
        }
    }

    
    return dp[0][budget]; 
}


int main(){

    int d = f(); 
    if(d < 0){
        cout << "Denaro Insufficiente" << endl; 
    }
    else{
        cout << f() << endl; 
    }
   
    return 1; 

}