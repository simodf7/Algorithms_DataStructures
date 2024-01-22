#include <iostream>


using namespace std; 

int a[4][4] = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0}; 


bool isValid(int x, int y){
    
    for(int i=0; i<y; i++){ // checking row
        if(a[x][i] == 1){
            return false; 
        }
    }

    for(int i=0; i<y; i++){ // checking diagonal 1
        if(a[x+i+1][y-i-1] == 1){
            return false; 
        } 
    }

    for(int i=0; i<y; i++){ // checking diagonal 2
        if(a[x-i-1][y-i-1] == 1){
            return false; 
        } 
    }

    return true; 

}

void backtrack(int col){

    if(col == 4){
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                cout << a[i][j] << " ";
            }
            cout << endl; 
        }
        cout << endl; 
    }

    for(int i=0; i<4; i++){
        if(isValid(i,col)){
            a[i][col] = 1; 
            backtrack(col+1);  
            a[i][col] = 0; 
        }   
    }
    


}

int main(){

    backtrack(0); 


    return 1; 
}