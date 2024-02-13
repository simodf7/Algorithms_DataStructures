#include <iostream>
#include <vector>
using namespace std; 

// Si consideri un algoritmo di tipo Divide et Impera D che opera su un array di interi con 1 ≤ n ≤ 1000
// elementi. Al primo passo l’algoritmo divide l’array in due parti; successivamente continua a dividere
// solo uno dei due sotto-array. Il numero di divisioni da fare e l’insieme dei pivot da usare (ossia i punti
// in cui si dovrà suddividere l’array) sono dati in ingresso. Ad ogni operazione di suddivisione fatta da
// Alg è associato un costo, che è pari al numero di elementi dell’array (o del sotto-array) da
// suddividere. È facile notare che selezioni diverse nell'ordine dei pivot (ossia dove suddividere prima)
// possono portare a costi diversi. Ad esempio, si consideri un array di 100 elementi, e siano i possibili
// pivot 25, 50 e 75. Ci sono diverse scelte. L’algoritmo D può suddividere prima a 25, poi a 50, poi a
// 75. Questo porta ad un costo di 100 elementi + 75 elementi + 50 elementi = 225 perché il primo
// array era di 100 elementi, il secondo, risultante dalla prima suddivisione, di 75 e l'ultima, risultante
// dalla seconda suddivisione, di 50. Un’altra scelta potrebbe essere scegliere come pivot 50, poi a 25,
// poi a 75. Questo porterebbe a un costo di 100 + 50 + 50 = 200, che è migliore. Si progetti un algoritmo
// per determinare il costo minimo che D impiega per suddividere l’array il numero di volte indicato


int dim = 100;
int pivot[3] = {25,50,75}; 
int N = 3; 


int minimumCost(int index, int d, vector<int>& used){

    if(index == 3){
        return 0; 
    }


    int result = 10000; 
    for(int i = 0; i<N; i++){
        if(used[i] != 1){
            used[i] = 1; 
            result = min(result, d + minimumCost(index+1, dim-pivot[index], used)); 
            used[i] = 0; 
        }
        
    }


    return result; 

}


int main(){

    vector<int> used(3,0); 
    cout << minimumCost(0, dim, used); 

    return 1; 
}