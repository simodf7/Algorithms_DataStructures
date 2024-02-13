#include <iostream>
#include <vector>
using namespace std; 

// Sia data un’espressione con sole addizioni e moltiplicazioni di numeri interi positivi, ma senza
// parentesi. Si scriva un algoritmo per determinare il valore massimo e il valore minimo che si possono
// ottenere posizionando opportunamente le parentesi nell'espressione.
// INPUT
// Ogni riga è un caso di test e contiene un’espressione. Lo 0 termina i casi di test.
// OUTPUT
// Ogni riga riporta due interi che rappresentano, rispettivamente, il massimo ed il minimo ottenibile
// dall’espressione corrispondente.
// Sample Input
// 2+4*2*3+7
// 3*14+19+3*10
// 0
// Sample Output
// 120 33
// 1080 91

string expression = "2+4*2*3+7"; 

vector<vector<int>> dp(expression.size(), vector<int>(expression.size(), -1)); 

int max_value(int i, int j){


    if(i==j){
        return expression[i] - '0'; 
    }   

    if(dp[i][j] != -1) return dp[i][j]; 



    int result = -1000; 
    for(int k = i+1; k<j; k++){ // scelgo il k per partizionare

        if(expression[k] == '+'){
            result = max(result, max_value(i, k-1) + max_value(k+1, j)); 
        }
        else if(expression[k] == '*'){
            result = max(result, max_value(i,k-1) * max_value(k+1, j)) ; 
        }
        else{
            continue; 
        }
    }
    
    return dp[i][j] = result; 

}

int main(){

    cout << max_value(0,expression.length()-1); 
    return 1;
}