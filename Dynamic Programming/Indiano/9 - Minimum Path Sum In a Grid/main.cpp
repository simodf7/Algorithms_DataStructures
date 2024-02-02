#include <iostream>
#include <vector>
using namespace std; 

// Ninjaland is a country in the shape of a 2-Dimensional grid 'GRID', with 'N' rows and 'M' columns. 
// Each point in the grid has some cost associated with it.


// Find a path from top left i.e. (0, 0) to the bottom right i.e. ('N' - 1, 'M' - 1) 
// which minimizes the sum of the cost of all the numbers along the path. You need to tell the minimum sum of that path.


// Note:

// You can only move down or right at any point in time.

int grid [2][3] = {
    5, 9, 6,
    11, 5, 2
};

vector<vector<int>> dp(2, vector<int>(3,-1));


int minimumPath(int x, int y){

    if(x == 1 &&  y == 2){
        return grid[x][y]; 
    }


    if(x<0 || x>1 || y<0 || y>2){
        return 10000; 
    }


    if(dp[x][y] != -1){
        return dp[x][y]; 
    }

    int down = grid[x][y] + minimumPath(x+1, y); 
    int right = grid[x][y] + minimumPath(x, y+1); 


    dp[x][y] = min(down, right); 
    return dp[x][y]; 

}



int main(){

    cout << minimumPath(0,0) << endl ; 
    return 1; 
}
