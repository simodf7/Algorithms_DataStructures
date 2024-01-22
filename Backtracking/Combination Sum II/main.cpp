#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int arr[7] = {10,1,2,7,6,1,5};
int target = 8; 
vector<int> ds; 

void backtrack(int index, int sum){

    if(index > 6){
        return; 
    }

    if(sum == target){
        for(auto elem:ds){
            cout << elem << " "; 
        }
        cout << endl; 
        return; 
    }

    if(sum > target){
        return; 
    }


    for(int i = index; i<6; i++){ 
        if(i>index && arr[i] == arr[i-1]) continue; 
        if(arr[i] > target) break; 
        // pick element
        ds.push_back(arr[i]); 
        backtrack(i+1, sum + arr[i]); 
        // pick maybe the next element
        ds.pop_back(); 
    }



}


int main(){

    sort(begin(arr), end(arr)); 
    backtrack(0,0); 


    return 1; 
}

