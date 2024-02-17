#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 


// PROBLEMA
// Un artigiano deve svolgere N lavori (ordini dai clienti). Egli può svolgere un solo lavoro al giorno. Per
// ogni i-esimo lavoro, è noto Ti (1 ≤ Ti ≤ 1000), un intero che indica il tempo in giorni impiegato
// dall’artigiano per finire il lavoro. Per ogni giorno di ritardo accumulato prima di iniziare a lavorare
// l'i-esimo ordine, l’artigiano deve pagare una penale di Si (1 ≤ Si ≤ 10000) centesimi di euro. Si
// implementi un programma per trovare la sequenza dei lavori che comporta la minima somma di
// penali.

// Osservazione: data una coppia di lavori i, j, la decisione di schedulare prima i o prima j non impatta
// sul costo totale dei restanti N-2 lavori; non è dunque necessario controllare ogni possibile
// permutazione.

// Greedy = prendere l'elemento che ha il minor rapporto tra giorni_necessari e penale (o il maggior rapporto tra penale e giorni)
// l'ultima considerazione infatti mi assicura che la scelta locale mi porta a quella ottima
// La complessita' e' interamente a carico della funzione sort, di cui non conosco il costo + il costo per scorrere il vettore ordinato O(n)

// anche qui e' necessario premere una seconda volta per avere il secondo output.

int N; 

struct job{
    int index;
    float tempo; 
    float penale; 
};

vector<job> jobs; 

bool compare(const job& j1, const job& j2 ){
    // float r1 = j1.tempo/j1.penale;  // minor rapporto tempo penale
    // float r2 = j2.tempo/j2.penale; 
    // return r1 < r2;

    float r1 = j1.penale/j1.tempo;   // maggior rapporto penale tempo
    float r2 = j2.penale/j2.tempo; 
    return r1 > r2;  
}


void solve(){

    sort(jobs.begin(), jobs.end(), compare); 

    for(auto job: jobs){
        cout << job.index << " "; 
    }
    cout << endl; 


}




int main(){

    int T, i=1; 

    cin >> T;

    while(T--){
 
        cin >> N;

        float tempo, penale;  

        for(int i=0; i<N; i++){
            cin >> tempo >> penale; 
            jobs.push_back({i+1, tempo, penale}); 
        }

        cout << "Case#" << i << ": "; 
        solve(); 
        ++i; 

        jobs.clear(); 
        cout << endl; 

    }


    return 1; 
}