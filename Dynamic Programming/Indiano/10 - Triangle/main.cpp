#include <iostream>
#include <vector>
using namespace std; 

// You are given a triangular array/list 'TRIANGLE'. Your task is to return the minimum path sum to reach from the top to the bottom row.

// The triangle array will have N rows and the i-th row, where 0 <= i < N will have i + 1 elements.

// You can move only to the adjacent number of row below each step. 
// For example, if you are at index j in row i, then you can move to i or i + 1 index in row j + 1 in each step.
// For Example :

// If the array given is 'TRIANGLE' = [[1], [2,3], [3,6,7], [8,9,6,1]] the triangle array will look like:

// 1
// 2,3
// 3,6,7
// 8,9,6,10

// For the given triangle array the minimum sum path would be 1->2->3->8. Hence the answer would be 14


vector<vector<int>> triangle{{1},
                                   {2, 3},
                                   {3, 6, 7},
                                   {8, 9, 6, 10}};

vector<vector<int>> dp(4, vector<int>(4, -1)); 


int minimumPath(int x, int y){


    if(x == 3){
        return triangle[x][y]; 
    }

    if(x > 3 || y > 3){
        return 10000; 
    }

    if(dp[x][y] != -1){
        return dp[x][y]; 
    }

    int down = triangle[x][y] + minimumPath(x+1, y); 
    int diagonal = triangle[x][y] + minimumPath(x+1, y+1); 


    dp[x][y] = min(down, diagonal); 

    return dp[x][y]; 
}


int main(){
    cout << minimumPath(0,0) << endl;
    return 1;
}

