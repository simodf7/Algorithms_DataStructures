#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int arr[3] = {3,1,2}; 
vector<int> ds; 

void backtrack(int index, int sum){

    if(index == 3){
        ds.push_back(sum);
        return; 
    }


    backtrack(index+1, sum+arr[index]); 
    backtrack(index+1, sum);
}


int main(){

    backtrack(0,0); 
    sort(ds.begin(), ds.end()); 
    for(auto elem: ds){
        cout << elem << " "; 
    }


    return 1; 
}