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



int maxPath(int x, int y){

    if(y<0 || y>3){
        return -10000; 
    }

    if(x == 3){
        return grid[x][y]; 
    }

   

    if(dp[x][y] != 0){
        return dp[x][y]; 
    }
    

    int down = grid[x][y] + maxPath(x+1, y); 
    int down_left = grid[x][y] + maxPath(x+1, y-1); 
    int down_right = grid[x][y] + maxPath(x+1, y+1); 


    dp[x][y] = max(down, max(down_left, down_right)); 

    return dp[x][y]; 

}


int main(){

    int count = 0; 

    for(int j=0; j<3; j++){
        count = max(count, maxPath(0, j)); 
    }

    cout << count << endl;

    return 1; 
}