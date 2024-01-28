#include <iostream>
#include <vector>

using namespace std; 

// Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. 

// Example 1:

// Input: nums = [4,6,7,7]
// Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]

// Example 2:

// Input: nums = [4,4,3,2,1]
// Output: [[4,4]

int nums[4] = {4,6,7,7}; 
vector<int> current; 


void backtrack(int index){

    if(index == 4){
        if(current.size() ==1){
            return; 
        }
        for(auto elem: current){
            cout << elem << " "; 
        }
        cout << endl;
        return; 
    }
    
    if(index > 1){
        if(current[index-1] < current[index-2]){
            return; 
        }
    }

    
    
    current.push_back(nums[index]); 
    backtrack(index+1); 
    current.pop_back(); 

    // not take
    backtrack(index+1); 



}


int main(){

    backtrack(0); 
    return 1; 
}