#include <iostream>
#include <vector>

using namespace std; 
int arr[4] = {2,3,6,7}; 
int target = 7; 
vector<int> ds; 

void backtrack(int index, int sum){

    if(index > 4){
        return;
    }
   
    if(sum == target){
        for(auto elem: ds){
            cout << elem << " "; 
        }
        cout << "\n"; 
        return; 
    }
     
    if(sum > target){ // pruning
        return; 
    }

    // pick
    ds.push_back(arr[index]); 
    backtrack(index, sum+arr[index]); 
    ds.pop_back(); 
    // not pick
    backtrack(index+1, sum); 

}



int main(){

    backtrack(0,0); 

    return 1; 
}