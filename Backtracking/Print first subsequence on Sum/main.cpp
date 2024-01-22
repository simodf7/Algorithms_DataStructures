#include <iostream>
#include <vector> 
using namespace std; 

int arr[3] = {1,2,1}; 
vector<int> ds; 
int calls = 0; 


bool backtrack(int index, int sum){

    calls++; 

    if(index == 3){
        if(sum == 2){
            for(auto element:ds){
                cout << element << " "; 
            }
            cout << "\n"; 
            return true; 
        }
        return false; 
    }

    if(index < 3 && sum > 2){ // pruning ? 
        return false; 
    }


    ds.push_back(arr[index]);
    if(backtrack(index+1, sum+arr[index])) return true; 
    ds.pop_back();
    if(backtrack(index+1, sum)) return true; 

    return false; 

}

int main(){

    backtrack(0,0); 
    cout << "Calls: " << calls; 

    return 1; 
}