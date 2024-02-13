#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

// PROBLEMA 1
// Si considerino N basi militari dislocate lungo il confine tra due stati, contrassegnate da coordinate
// geografiche unidimensionali rappresentate da numeri interi distinti compresi tra 1 e 50, <x1, x2, …
// xN>. Dunque, la base 1 è alla posizione x1, la base 2 alla posizione x2, ecc. Si assume che ciascuna di
// queste basi abbia una omologa base dislocata dall’altro lato del confine, rappresentate da numeri
// interi distinti <y1, y2, …yN>, con cui dialogare tramite un canale dedicato. La base x1 può comunicare
// solo con y1, x2 solo con y2, …e così via. Si implementi un algoritmo che determini il massimo numero
// di collegamenti dedicati tra le basi che è possibile dispiegare, con il vincolo che i canali di
// comunicazione non si devono mai incrociare, per ragioni di sicurezza. Ad esempio, con:
// X = <8 5 3 2>
// Y = <3 4 7 6>
// stiamo indicando che la base alla posizione x1 = 8 può comunicare solo con la base alla posizione y1
// = 3, x2 = 5 con y2 = 4, e così via. Il numero massimo di canali senza incrocio in questo caso è 2, che si
// ottiene collegando l’ultima coppia (x4 = 2, y4 = 6) e la penultima coppia (x3 = 3, y3 = 7). Infatti,
// ordinando rispetto alle coordinate, abbiamo:
// 2 3 5 8
//  \ \
//   \ \
//    \ \
// 3 4 6 7

int N; 
vector<pair<int,int>> x; 
vector<pair<int, int>> y; 




int solve(){

    auto compare = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.first < b.first; // Sort based on the first element of each pair
    };

    sort(x.begin(), x.end(), compare);
    sort(y.begin(), y.end(), compare); 

    vector<vector<int>> dp(x.size()+1, vector<int>(y.size()+1, -1)); 

    for(int i=0; i<=x.size(); i++){
        dp[i][0] = 0; 
    }

    for(int j=0; j<=y.size(); j++){
        dp[0][j] = 0; 
    }

    for(int i=1; i<= x.size(); i++){
        for(int j=1; j<=y.size(); j++){
            if(x[i-1].second == y[j-1].second){
                dp[i][j] = 1 + dp[i-1][j-1]; 
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
        }
    }


    return dp[x.size()][y.size()];
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    int T, i=1;

    cin >> T; 
    
    while(T--){

        cin >> N; 
        int num; 

        for(int i=0; i<N; i++){
            cin >> num; 
            x.push_back({num, i+1}); 
        }

        for(int i=0; i<N; i++){
            cin >> num; 
            y.push_back({num, i+1}); 
        }

        cout << "Case#" << i << ": " << solve() << endl; 
        ++i; 
        x.clear(); 
        y.clear(); 

    }



    
    return 1; 

}


