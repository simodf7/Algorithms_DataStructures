#include <iostream>
#include <vector>
using namespace std; 


// Given a chain of matrices A1, A2, A3,.....An. Your task is to find out the minimum cost to multiply these matrices.
// The cost of matrix multiplication is defined as the number of scalar multiplications. 
// A Chain of matrices A1, A2, A3,.....An is represented by a sequence of numbers in an array ‘arr’ 
// where the dimension of 1st matrix is equal to arr[0] * arr[1] , 2nd matrix is arr[1] * arr[2], and so on.
// For example:

// For arr[ ] = { 10, 20, 30, 40}, matrix A1 = [10 * 20], A2 = [20 * 30], A3 = [30 * 40]

// Scalar multiplication of matrix with dimension 10 * 20 is equal to 200.

int arr[4] = {4,5,3,2};
int N = 4; 

vector<vector<int>> dp(4, vector<int>(4, -1)); 


int matrix_Multiplication(int i, int j){

    if(i==j) return 0; //only matrix Ai
    if(dp[i][j] != -1) return dp[i][j]; 

    // dobbiamo scegliere k per partizionare

    int steps = 1000000; 
    for(int k=i; k<j; k++){
        steps = min(steps, matrix_Multiplication(i,k) + matrix_Multiplication(k+1, j) + arr[i-1]*arr[k]*arr[j]); 
    }


    return dp[i][j] = steps; 
}


int main(){

    cout << matrix_Multiplication(1, N-1) << endl; 
    return 1; 

}
