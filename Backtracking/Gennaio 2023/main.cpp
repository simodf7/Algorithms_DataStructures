#include <iostream> 
#include <vector>

using namespace std; 

int N, M; 
char a[100][100]; 
int dir[8][2] = {{0,-1}, {0,1}, {-1,0}, {1, 0}, {-1, -1}, {1,1}, {-1,1}, {1, -1}}; 
string word; 
vector<vector<int>> dp(100, vector<int>(10, 0)); 

bool isValid(int x, int y){
    return x>=0 && x<N && y>=0 && y<M && dp[x][y] == 0; 
}

bool backtrack(int x, int y, int ind){

    if(ind == word.length()){
        return true; 
    }

    if(isValid(x,y)){

        dp[x][y] = ind + 1; 

        for(int i=0; i<8; i++){
            int dx = dir[i][0]; 
            int dy = dir[i][1]; 
            if (backtrack(x+dx, y+dy, ind+1)) return true;
        }

        dp[x][y] = 0; 

    }

    return false; 
}


vector<pair<int,int>> getResult(){

    vector<pair<int,int>> r; 
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(dp[i][j] > 0){
                r.push_back({i+1, j+1}); 
            }
        }
    }

    return r; 
}


int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    int T; 

    cin >> T; 


    cout << "\n\n";
    
    while(T--){

        cout << "OKAY CAPO \n";
        cin >> word >> N >> M; 

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin >> a[i][j]; 
            }
        }

        vector<pair<int,int>> result; 

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(backtrack(i,j,0)){
                    result = getResult(); 
                }
            }
        }

        if (!result.empty()) {
            for (const auto& cell : result) {
                cout << cell.first << " " << cell.second << endl;
            }
        } else {
            cout << "END" << endl;
        }

    }




    return 1; 


}