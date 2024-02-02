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

int uniquePath(int x, int y){


    if(x == 2 && y == 2){
        return 1;
    }

    if(x<0 || x>2 || y<0 || y>2 || grid[x][y] == -1){
        return 0; 
    }

    if(dp[x][y] != -1){
        return dp[x][y]; 
    }

    int count = 0; 

    for(int i=0; i<2; i++){
        int new_x = x + moves[i][0];
        int new_y = y + moves[i][1];
        count += uniquePath(new_x, new_y); 
    }

    dp[x][y] = count; 

    return count; 
}




int main(){

    cout << uniquePath(0,0) << endl; 
    return 1; 
}