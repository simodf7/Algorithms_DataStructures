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

int dp [2][3] = {
    0, 0, 0,
    0, 0, 0
};

// vector<vector<int>> dp(2, vector<int>(3,-1));


int minimumPath(){


    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){

            if(i==0 && j==0){
                dp[i][j] = grid[i][j]; 
                continue;
            }


            int up = 10000;
            int left = 10000;
            
            if(i>0){
                up = grid[i][j] +  dp[i-1][j]; 
            } 
            
            if(j>0){
                left = grid[i][j] + dp[i][j-1]; 
            }


            dp[i][j] = min(up, left); 

        }
    }

 
    return dp[1][2]; 

}



int main(){

    cout << minimumPath() << endl ; 
    return 1; 
}
