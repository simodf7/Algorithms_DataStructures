#include <iostream>
#include <vector>
using namespace std;

int arr[4] = {4, 5, 3, 2};
int N = 4;

vector<vector<int>> dp(4, vector<int>(4, -1));

int matrix_Multiplication() {
    // Initialize base cases
    for (int i = 1; i < N; ++i) {
        dp[i][i] = 0;
    }


    for (int i = N-1; i >= 1; --i) { 
        for(int j=i+1; j<N; ++j){ 
            dp[i][j] = 10000;

            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]);
            }
        }
    }
    

    return dp[1][N - 1];
}

int main() {
    cout << matrix_Multiplication() << endl;
    return 0;
}
