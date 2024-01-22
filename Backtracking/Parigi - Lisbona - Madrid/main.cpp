#include <iostream> 
#include <vector>


// sbagliato
using namespace std; 

string first, second; 
int dir[2][2] = {{1,0},{0,1}}; 
vector<vector<int>> dp(10, vector<int>(10, -1));



int solve(int x, int y){

    if(x>first.length() || y>second.length()){
        return 0; 
    }


    if (dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;

    int next_x, next_y; 
    
    if(first[next_x] == second[next_y]){
        next_x = x+1; 
        next_y = y+1;
        dp[x][y] = 1 + solve(next_x, next_y); 
    }

    for (int i = 0; i<2; i++){
        next_x = x+dir[i][0];
        next_y = y+dir[i][1];

        if(first[next_x] == second[next_y]){
            dp[x][y] = max(solve(next_x, next_y) +1, dp[x][y]);
        }
    }
    return dp[x][y];
}





int main(){

    ios::sync_with_stdio(0); 
    cin.tie(0);

    int i=1; 

    while(1){

        cin >> first; 
        if(first == "#"){
            break;
        }

        
        cin >> second; 

        int ans = 0; 

        for(int i=0; i<first.length(); i++){
            for(int j=0; j<second.length(); j++){
                ans = max(ans, solve(0,0)); 
            }
        }


        cout << "Case# " << i << ": numero massimo = " <<  ans << "\n";    
        i++;
    }
    




}