#include <iostream>
#include <vector>

using namespace std; 

// Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.

// Example 1:

// Input: n = 2
// Output: 91
// Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, excluding 11,22,33,44,55,66,77,88,99

// Example 2:

// Input: n = 0
// Output: 1

int n=3;
int used[10] = {0,0,0,0,0,0,0,0,0,0};

int backtrack(int index){

    if(index == n){
        return 1; 
    }

    int count = 0; 

    for(int i=0; i<=9; i++){
        if(i == 0) {
            count += backtrack(index+1);
        }
        else if(used[i] != 1){
            used[i] = 1; 
            count += backtrack(index+1); 
            used[i] = 0; 
        }
    }


    return count; 
}


int main(){
 
    cout << backtrack(0);


    return 1; 
}
