#include <iostream>

using namespace std; 

int board[9][9]  = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

bool isPossible(int x, int y, int value){

    for(int i=0; i<9; i++){

        if(board[i][y] == value){ // check row
            return false; 
        }

        if(board[x][i] == value){ // check column
            return false;
        }
    }

    // check grid
    int r = x - x%3;  
    int c = y - y%3; 

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i+r][j+c] == value){
                return false; 
            }
        }
    }

    return true;


}


bool backtrack(){
    
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(board[i][j] == 0){

                for(int k=1; k<=9; k++){
                    if(isPossible(i,j,k)){
                        board[i][j] = k; 
                        if(backtrack()) return true;  
                        board[i][j] = 0; 
                    }
                }

                return false;

            }

        }
    }



}


int main(){ 


    if(backtrack()){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    };


    return 1; 
}