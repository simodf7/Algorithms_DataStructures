#include <iostream>
#include <vector>
using namespace std; 

int arr[3] = {1,2,3};
int visited[3] = {0,0,0};  
vector<int> ds; 


void backtrack(int index){

    if(index == 3){
        for(auto elem: ds){
            cout << elem << " ";
        }
        cout << endl; 
    }

    // 1 - 2 - 3
    // 1 - 1 - 1 



    for(int i=0; i<3; i++){
        if(visited[i] == 1) continue; 
        ds.push_back(arr[i]);
        visited[i] = 1; 
        backtrack(index+1); 
        visited[i] = 0; 
        ds.pop_back(); 
    }


}

int main(){


    backtrack(0); 


    return 1; 
}