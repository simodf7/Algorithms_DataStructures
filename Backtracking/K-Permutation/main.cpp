#include <iostream>
#include <vector>

using namespace std; 

int n=3;
int visited[3] = {0,0,0}; 
int k=3; 
vector<int> ds; 

int num = 0; 

bool backtrack(int index){

    if(index == 3){
        if(num != k){
            num++; 
        }
        else{
            for(auto elem: ds){
                cout << elem << " "; 
            }
            cout << endl; 
            return true;
        }
        return false;
        
    }

    for(int i=1; i<=3; i++){
        if(visited[i-1] == 1) continue;
        else {
            visited[i-1] = 1; 
            ds.push_back(i); 
            if(backtrack(index+1)) return true; 
            ds.pop_back(); 
            visited[i-1] = 0; 
        }
    }

    return false; 

}

int main(){

    backtrack(0);

    return 1; 
}