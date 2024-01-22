#include <iostream> 
#include <vector>

using namespace std; 

int N, M; 
char a[100][100]; 
int dir[8][2] = {{0,-1}, {0,1}, {-1,0}, {1, 0}, {-1, -1}, {1,1}, {-1,1}, {1, -1}}; 
string word; 
vector<pair<int,int>> ds; 

bool isValid(int x, int y,int ind){
    return x>=0 && x<N && y>=0 && y<M && a[x][y] == word[ind];  
}

bool backtrack(int x, int y, int ind){

    
    if(ind == word.size()){
        ds.pop_back();
        for(auto couple: ds){
            cout << couple.first << " " << couple.second << "\n";  
        }
        return true; 
    }

    if(!isValid(x,y, ind)) return false;

    for(int i=0; i<8; i++){
        int next_x = x + dir[i][0];
        int next_y = y + dir[i][1];  
        ds.push_back({next_x+1,next_y+1}); 
        if(backtrack(next_x, next_y, ind+1)) return true; 
        ds.pop_back(); 
    }

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

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                ds.push_back({i+1,j+1}); 
                if(backtrack(i,j,0)) break;
                ds.pop_back(); 
            }
        }

        ds.clear();

    }

    




    return 1; 


}