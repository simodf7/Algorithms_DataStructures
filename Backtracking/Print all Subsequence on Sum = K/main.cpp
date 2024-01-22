#include <iostream>
#include <vector> 
using namespace std; 

int arr[3] = {1,2,1}; 
vector<int> ds; 
int calls = 0; 


void backtrack(int index, int sum){

    calls++; 

    if(index == 3){
        if(sum == 2){
            for(auto element:ds){
                cout << element << " "; 
            }
            cout << "\n"; 
        }
        return; 
    }

    if(index < 3 && sum > 2){ // pruning ? 
        return; 
    }


    ds.push_back(arr[index]);
    backtrack(index+1, sum+arr[index]); 
    ds.pop_back();
    backtrack(index+1, sum); 



}

int main(){

    backtrack(0,0); 
    cout << "Calls: " << calls; 

    return 1; 
}