#include <iostream>
#include <string>
#include <vector>


/// SEG FAULT :((((

using namespace std; 

int R,C;
string name;  
int a[100][100]; 
int dp[100][100]; 
int dir [4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
int max_run; 



int isValid(int x, int y, int prev_x, int prev_y){
    return x>=0 && x<R && y>=0 && y<C && a[x][y] <= a[prev_x][prev_y]; 
}


int longest_run(int x, int y){

    if(dp[x][y] != -1){
        return dp[x][y]; 
    }


    max_run = 1; 
    int new_x, new_y; 

    for(int i=0; i<4; i++){
        new_x = x + dir[i][0]; 
        new_y = y + dir[i][1]; 
        if(isValid(new_x, new_y, x, y)){
            max_run = max(max_run, 1+longest_run(new_x, new_y)); 
        }
    }
        

    dp[x][y] = max_run; 
    return max_run; 

}




int main(){

    ios::sync_with_stdio(0); 
    cin.tie(0); 

    int T; 

    cin >> T; 
        


    while(T--){
    
        
        cin >> name >> R >> C; 

        

        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                cin >> a[i][j]; 
            }
        }

    
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                    dp[i][j] = -1; 
            }
        } 
        int ans = 0; 

        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                ans = max(ans, longest_run(i,j)); 
            }
        }

        cout << "\n"; 

        cout << "Case#: " << ans << "\n"; 

        

    }



    return 1; 
}