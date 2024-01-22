#include <iostream>
using namespace std; 

int arr[3] = {1,2,3}; 
int visited[3] = {0,0,0}; 

int backtrack(int index){

    if(index == 3){
        return 1; 
    }

    int count = 0; 


    for(int i=0; i<3;i++){
        if(visited[i] == 1) continue; 
        visited[i] = 1; 
        count += backtrack(index+1); 
        visited[i] = 0; 
    }

    return count; 

}

int main(){

    cout << "Count: " << backtrack(0); 
    return 1; 
}