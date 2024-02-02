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


int minimumPath(){


    for(int j = 0; j<4; j++){
        dp[3][j] = triangle[3][j]; 
    }


    for(int i=2; i>=0; i--){
        for(int j=i; j>=0; j--){

            int down = triangle[i][j] + dp[i+1][j];         
            int diagonal = triangle[i][j] + dp[i+1][j+1]; 


            dp[i][j] = min(down, diagonal); 

        


        }
    }



    return dp[0][0]; 
}


int main(){
    cout << minimumPath() << endl;
    return 1;
}

