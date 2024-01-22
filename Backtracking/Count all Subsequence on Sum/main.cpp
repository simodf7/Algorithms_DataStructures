#include <iostream>
#include <vector> 
using namespace std; 

int arr[3] = {1,2,1}; 
vector<int> ds; 
int calls = 0; 


int backtrack(int index, int sum){

    calls++; 

    if(index == 3){
        if(sum == 2){
            return 1; 
        }
        return 0; 
    }

    if(index < 3 && sum > 2){ // pruning ? 
        return 0; 
    }

    // pick element arr[index]
    int l = backtrack(index+1, sum+arr[index]);
    // not picking element arr[index] 
    int r = backtrack(index+1, sum); 

    return l+r; 
}

int main(){

    cout << "Count: " << backtrack(0,0) << endl; 
    cout << "Calls: " << calls; 

    return 1; 
}