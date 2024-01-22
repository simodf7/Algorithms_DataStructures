#include <iostream>
using namespace std; 

int arr[3] = {1,2,3}; 
int visited[3] = {0,0,0}; 

void swap(int x, int y){
    int temp = arr[x]; 
    arr[x] = arr[y]; 
    arr[y] = temp; 
}


void backtrack(int index){

    if(index == 3){
        for(auto elem: arr){
            cout << elem << " "; 
        }
        cout << endl; 
    }

    for(int i=index; i<3; i++){
        swap(index, i); 
        backtrack(index+1);
        swap(i,index); 
    }


}


int main(){

    backtrack(0); 


    return 1; 
}