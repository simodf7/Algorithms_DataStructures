#include <iostream>
using namespace std; 

int N, M; 
int a[100][100]; 
int sol[100][100]; 

void printSolution(){

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(j!=M-1) cout << sol[i][j] << " "; 
            else cout << sol[i][j] << "\n"; 
        }
    }

}

bool isValidMove(int x, int y){

    if(x >= 0 && x<N && y>=0 && y<M && a[x][y] == 1){
        return true; 
    }


    return false; 
}

bool solveMazeUtil(int x, int y){

    if(x == N-1 & y == M-1){
        sol[x][y] = 1; 
        return true; 
    }

    if (isValidMove(x,y) == true){

        // make move
        sol[x][y] = 1; 

        // candidati ?

        // possiamo muoverci verso destra 
        if (solveMazeUtil(x+1, y) == true){
            return true; 
        }

        // oppure in basso se a destra non abbiamo trovato soluzione
        if (solveMazeUtil(x, y+1) == true){
            return true; 
        }

        // undo move
        // backtrack
        sol[x][y] = 0; 
        return false; 

    }

}


void solveMaze(){

    if (solveMazeUtil(0,0) == false) cout << "NO SOLUTION \n"; 
    else printSolution(); 
}





int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int T, i=1; 

    cin >> T; 

    while(T--){

        cin >> N >> M; 

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin >> a[i][j]; 
            }
        }

        cout << "Case#" << i << " \n"; 
        solveMaze(); 
        ++i; 

    }




    return 1; 
}