#include <iostream>

using namespace std; 

string word = "ABCCED"; 
char board[3][4] = {
    {'A','B','C','E'},
    {'S','F','C','S'},
    {'A','D','E','E'}
}; 


int dir[4][2] = {{0,-1}, {0,1}, {1,0}, {-1,0}}; 

bool backtrack(int x, int y, int index){

    if(index == word.size()){
        return true; 
    }

    if(board[x][y] != word[index] || x < 0 || x > 3 || y<0 || y>4 ){
        return false; 
    }

    char t = board[x][y]; 
    board[x][y] = '#'; 

    for(int i=0; i<4; i++){
        int next_x = x + dir[i][0]; 
        int next_y = y + dir[i][1]; 
        if(backtrack(next_x, next_y, index+1)) return true; 
    }
    
    board[x][y] = t;
    return false; 


}


int main(){

    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            if(backtrack(i,j,0)) {
                cout << "true";
                return 1;
            }
        }
    }   

    cout << "false";

    return 1; 
}