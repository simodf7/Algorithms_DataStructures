#include <iostream>
#include <vector>

using namespace std; 

// Suppose you have n integers labeled 1 through n. 
//A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

//     perm[i] is divisible by i.
//     i is divisible by perm[i].

// Given an integer n, return the number of the beautiful arrangements that you can construct. 

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: 
// The first beautiful arrangement is [1,2]:
//     - perm[1] = 1 is divisible by i = 1
//     - perm[2] = 2 is divisible by i = 2
// The second beautiful arrangement is [2,1]:
//     - perm[1] = 2 is divisible by i = 1
//     - i = 2 is divisible by perm[2] = 1

// Example 2:

// Input: n = 1
// Output: 1

int n = 1;
vector<int> used(1,0);  


int backtrack(int index){

    if(index == n){
        return 1; 
    }

    int count = 0; 

    for(int i=1; i<=n; i++){
        if(used[i-1] != 1){
            used[i-1] = 1; 
            if(i % (index+1) == 0 || (index+1) % i == 0){
                count += backtrack(index+1);
            }
            used[i-1] = 0; 
        } 
    }

    return count; 
}



int main(){

    cout << backtrack(0);

    return 1; 
}