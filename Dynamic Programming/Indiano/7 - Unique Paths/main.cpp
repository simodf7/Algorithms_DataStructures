#include <iostream>
#include <vector>
using namespace std; 

int M = 3 , N = 2; 
int calls = 0; 
vector<vector<int>> dp(10, vector<int>(10,0)); 


int uniquePaths(int x, int y){  // memoization

    calls++;

    if(x == M-1 && y == N-1){
        return 1; 
    } 


    if(x > M-1 || y > N-1){
        return 0; 
    }

    if(dp[x][y] != -1){
        return dp[x][y]; 
    }



    int right_move = uniquePaths(x, y+1); 
    int bottom_move = uniquePaths(x+1, y); 

    dp[x][y] = right_move + bottom_move; 
    return dp[x][y];    
}


int uniquePaths_TAB(){ // Tabulation
    // vedi indiano è sbagliata
 
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){

            if(i == 0 && j == 0) dp[i][j] = 1; 
            else{

                int right_move = 0; 
                int bottom_move = 0;

                if(j<= N-1) {
                    right_move = dp[i][j+1]; 
                }

                if(i <= M-1) {
                    bottom_move = dp[i+1][j]; 
                }
    
                dp[i][j] = right_move + bottom_move; 
            }
        
        }
    }

    return dp[0][0]; 
}


int main(){



    cout << uniquePaths_TAB();  
    return 1; 
}