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


int max_value(){

    int N = expression.size(); 

    for(int i=0; i<N; i++){
        dp[i][i] = expression[i] - '0'; 
    }


    for(int i = N-1; i>=0; i--){ 
        for(int j=i+1; j<N; j++){

            int result = -1000; 
            for(int k = i+1; k<j; k++){ // scelgo il k per partizionare

                if(expression[k] == '+'){
                    result = max(result, dp[i][k-1] + dp[k+1][j]);  
                }
                else if(expression[k] == '*'){
                    result = max(result, dp[i][k-1] * dp[k+1][j]) ; 
                }
                else{
                    continue; 
                }
            }
        }
    }

    
    
    return dp[0][N-1]; 

}

int main(){

    cout << max_value(); 
    return 1;
}