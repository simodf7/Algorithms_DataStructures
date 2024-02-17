#include <iostream>
#include <vector>
using namespace std; 

// PROBLEMA 1
// Dato un numero N e una lista di n numeri interi, si implementi un algoritmo di backtracking che
// trova tutte le somme distinte, utilizzando i numeri della lista, la cui somma è N (un numero può
// essere utilizzato all'interno di una somma tante volte quanto appare nell'elenco; inoltre, la somma
// può essere costituita anche da un singolo numero).


// Complessita' = O(^n)
// Non so perche ma va premuto di nuovo invio per avere il terzo output. 

int dim; 
int N; 
int arr[100]; 
vector<vector<int>> result; 
vector<int> ds; 

void backtrack(int index, int sum){

    if(sum == N){
        result.push_back(ds); 
        return; 
    }

    if(index == dim){
        return; 
    }


    if(sum > N){
        return; 
    }



    for(int i = index; i<dim; i++){ 
        if(i>index && arr[i] == arr[i-1]) continue;  // in questo modo evitiamo i duplicati 
        // es se abbiamo due numeri uguali consecutivi, il backtrack ci portera alla stessa soluzione
        // scegli questo elemento 
        ds.push_back(arr[i]); 
        backtrack(i+1, sum + arr[i]); 
        // pop e magari scegliamo il prossimo
        ds.pop_back(); 
    }

}


int main(){

    int T, i=1; 

    cin >> T; 

    while(T--){

        cin >> N >> dim; 


        for(int i=0; i<dim; i++){
            cin >> arr[i]; 
        }

        backtrack(0,0); 

        cout << "TEST" << endl; 


        if(result.size() == 0) cout << "NONE" << endl; 
        else{
            for(auto sum: result){
                for(int i=0; i<sum.size(); i++){
                    if(i == sum.size()-1) cout << sum[i]; 
                    else cout << sum[i] << "+"; 
                }
                cout << endl; 
            }
            cout << endl; 
        }
        

        result.clear(); 
        ds.clear();

    }

    
    return 1; 

}