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
    {1, 3, 3, 7}
}; 

vector<vector<int>> dp(n_classes+1, vector<int>(budget+1, -1)); 

int f(int c,int b){

    if(c == n_classes){
        return 0; 
    }

    if(dp[c][b] != -1) return dp[c][b]; 

    int spending = -1000; 
    for(int i=0; i<classes[c].size(); i++){
        if(classes[c][i] <= b){
            spending = max(spending, classes[c][i] + f(c+1, b- classes[c][i]));
        }
    }

    return dp[c][b] = spending; 
}


int main(){

    int d = f(0,budget); 
    if(d < 0){
        cout << "Denaro Insufficiente" << endl; 
    }
    else{
        cout << f(0, budget) << endl; 
    }
   
    return 1; 

}