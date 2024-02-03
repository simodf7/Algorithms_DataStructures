#include <iostream>
#include <vector>

using namespace std; 


// Ninja has a 'GRID' of size 'R' X 'C'. Each cell of the grid contains some chocolates.
// Ninja has two friends Alice and Bob, and he wants to collect as many chocolates as possible with the help of his friends.

// Initially, Alice is in the top-left position i.e. (0, 0), and Bob is in the top-right place i.e. (0, ‘C’ - 1) in the grid. 
// Each of them can move from their current cell to the cells just below them. 
// When anyone passes from any cell, he will pick all chocolates in it, and then the number of chocolates in that cell will become zero.
//  If both stay in the same cell, only one of them will pick the chocolates in it.

// If Alice or Bob is at (i, j) then they can move to (i + 1, j), (i + 1, j - 1) or (i + 1, j + 1). They will always stay inside the ‘GRID’.

// Your task is to find the maximum number of chocolates Ninja can collect with the help of his friends by following the above rules.
// Example:

// Input: ‘R’ = 3, ‘C’ = 4
//        ‘GRID’ = [[2, 3, 1, 2], [3, 4, 2, 2], [5, 6, 3, 5]]
// Output: 21

// Initially Alice is at the position (0,0) he can follow the path (0,0) -> (1,1) -> (2,1) and will collect 2 + 4 + 6 = 12 chocolates.

// Initially Bob is at the position (0, 3) and he can follow the path (0, 3) -> (1,3) -> (2, 3) and will colllect 2 + 2 + 5 = 9 chocolates.

// Hence the total number of chocolates collected will be 12 + 9 = 21. there is no other possible way to collect a greater number of chocolates than 21.

int grid[3][4] = {
   {2, 3, 1, 2}, 
   {3, 4, 2, 2}, 
   {5, 6, 3, 5}
};

int moves[3] = {0, -1, 1}; 

vector<vector<vector<int>>> dp(3, vector<vector<int>>(4, vector<int> (4, -1))); 


int maxChocolate(int x, int y_a, int y_b){
 
    if(y_a < 0 || y_b < 0 || y_a > 3 || y_b > 3){
        return -10000; 
    }
    
    if(x == 3){
        if(y_a == y_b) return grid[x][y_a]; 
        else return grid[x][y_a] + grid[x][y_b]; 
    }

    
    if(dp[x][y_a][y_b] != -1){
        return dp[x][y_a][y_b]; 
    } 


    

    int chocolates = -10000; 

    for(int i=0; i<3; i++){
        int new_ya = y_a + moves[i]; 

        for(int j=0; j<3; j++){

            int new_yb = y_b + moves[j]; 

            if(y_a == y_b) {
                chocolates = max(chocolates, grid[x][y_a] + maxChocolate(x+1,new_ya, new_yb)); 
            } else chocolates = max(chocolates, grid[x][y_a] + grid[x][y_b] + maxChocolate(x+1,new_ya, new_yb));


        }

            
    } 

    return dp[x][y_a][y_b] = chocolates; 
}


int main(){

    cout << maxChocolate(0,0,3); 
    return 1; 
}   