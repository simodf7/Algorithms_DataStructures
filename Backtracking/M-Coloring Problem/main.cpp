#include <iostream>

using namespace std; 

int M = 3; 
bool graph[4][4] = {
            {0, 1, 1, 1},
            {1, 0, 1, 0},
            {1, 1, 0, 1},
            {1, 0, 1, 0}
}; 

int color[4] = {0,0,0,0}; 


bool isPossible(int node, int c){

    for(int i=0; i<4; i++){
        if(graph[node][i] && color[i] == c){
            return false; 
        }
    }

    return true;
}



bool backtrack(int node){

    if(node == 4){
        return true; 
    }

    for(int i=1; i<=M; i++){
        if(isPossible(node, i)){
            color[node] = i; 
            if(backtrack(node+1)) return true; 
            color[node] = 0; 
        }
    }


    return false; 


    

}


int main (){

    if(backtrack(0)) {
        for(auto elem: color){
            cout << elem << " "; 
        }
        cout << endl; 
    } else cout << "No solution" << endl; 


    return 1; 
}