#include <iostream>
#include <vector>

using namespace std; 

// You have been given an N*M matrix filled with integer numbers, 
// find the maximum sum that can be obtained from a path starting from any cell in the first row to any cell in the last row.

// From a cell in a row, you can move to another cell directly below that row, or diagonally below left or right. 
// So from a particular cell (row, col), we can move in three directions i.e.

// Down: (row+1,col)
// Down left diagonal: (row+1,col-1)
// Down right diagonal: (row+1, col+1)


int grid[4][4] = {
    1, 2, 10, 4,
    100, 3, 2, 1,
    1, 1, 20, 2,
    1, 2, 2, 1
};

int dp[4][4] = {
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0
};



int maxPath(){


    for(int j=0; j<4; j++){
        dp[0][j] = grid[0][j]; 
    }

    for(int i=1; i<4; i++){
        for(int j=0; j<4; j++){


            int up = grid[i][j] + dp[i-1][j]; 
            int up_right = -10000; 
            int up_left = -10000; 

            if(j<3){
                up_right = grid[i][j] + dp[i-1][j+1]; 
            }
            
            if(j-1>=0){
                up_left = grid[i][j] + dp[i-1][j-1]; 
            }
            
            dp[i][j] = max(up, max(up_left, up_right)); 
        }
    }

    int maximum = -100; 
    for(int j=0; j<4; j++){
        maximum = max(maximum, dp[3][j]); 
    }


    return maximum; 

}


int main(){

    cout << maxPath() << endl; 
    
    return 1; 
}