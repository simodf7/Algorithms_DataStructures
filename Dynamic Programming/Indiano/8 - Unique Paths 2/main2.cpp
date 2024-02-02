#include <iostream>
#include <vector>
using namespace std; 

// Given a ‘N’ * ’M’ maze with obstacles, count and return the number of unique paths to reach the right-bottom cell from the top-left cell.
//  A cell in the given maze has a value '-1' if it is a blockage or dead-end, else 0. 
//  From a given cell, we are allowed to move to cells (i+1, j) and (i, j+1) only.
//   Since the answer can be large, print it modulo 10^9 + 7.
// For Example :

// Consider the maze below :
// 0 0 0 
// 0 -1 0 
// 0 0 0

// There are two ways to reach the bottom left corner - 

// (1, 1) -> (1, 2) -> (1, 3) -> (2, 3) -> (3, 3)
// (1, 1) -> (2, 1) -> (3, 1) -> (3, 2) -> (3, 3)

// Hence the answer for the above test case is 2.


int grid[3][3] = {
    0, 0,  0,  
    0, -1, 0, 
    0,  0,  0
};


int moves[2][2] = {{1,0}, {0,1}}; 
vector<vector<int>> dp(3, vector<int>(3, -1));

int uniquePath(){

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){

            if(i == 0 && j == 0){
                dp[i][j] = 1;
                continue;
            }

            if(i<0 || j < 0 || grid[i][j] == -1){
                dp[i][j] = 0; 
                continue;
            }

            int up = 0;
            int left = 0; 

            if(i>0){
                up = dp[i-1][j]; 
            }
            if(j>0){
                left = dp[i][j-1]; 
            }   
                

            dp[i][j] = up + left; 

        }
    }

    // il risultato è nell'ultima cella
    return dp[2][2];    

}




int main(){

    cout << uniquePath() << endl; 
    return 1; 
}