#include <iostream>
using namespace std; 

int N, T, M;
int times[100];  


// I traghetti fluviali servono sono usati per trasportare auto da una riva all’altra di un fiume. Le auto
// salgono sul traghetto da un'estremità, il traghetto attraversa il fiume e le auto escono dall'altra
// estremità del traghetto. Un traghetto può portare n auto in t minuti e tornare in t minuti.
// Sia m il numero di auto che arrivano al terminal dei traghetti entro un determinato orario.
// Qual è il minimo tempo entro cui tutte le auto possono essere trasportate attraverso il fiume? Qual
// è il numero minimo di viaggi che l'operatore deve effettuare per trasportare tutte le auto entro tale
// tempo?

// GREEDY ALGORITHM

// 0  // C = 1 
// 10 // C = 2, T = 10 + 20 = 30 ,  V = 1
// 20  // C = 1
// 30  // C = 2  T = 30 + 20 = 50  V  =2
// 40  // 1 
// 50   // 2 , T = 50 + 20 = 70  V = 3
// 60  // 1
// 70  // 2 T  = 70 + 20 = 90 V = 4
// 80  // 1
// 90  // 2 T = 90 + 20  V = 5

pair<int, int> solve(){

    // take the maximum car possible
    int current_time = 0;  
    int current_cars = 0; 
    int trips = 0; 


    for(int i=0; i<M; i++){

        current_cars++; 

        if(current_cars == N){
            current_cars = 0; 
            trips++; 
            current_time = times[i] + T; 
        }
        else if(M-i < N){
            trips++; 
            current_time += T; 
        }

        if(current_time < times[i]) current_time == times[i]; 

        
    }

    return {current_time, trips}; 


}


int main(){

    ios::sync_with_stdio(0); 
    cin.tie(0); 

    int C, i=1;

    cin >> C;


    while(C--){

        cin >> N >> T >> M; 

        for(int i=0; i<M; i++){
            cin >> times[i]; 
        }

        pair<int, int> result = solve(); 
        cout << "Case#" << i << ": " << result.first << " " << result.second << endl; 
        ++i; 

    }


    return 1; 
}