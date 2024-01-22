#include <iostream>
using namespace std;

int Y = 4; 
int arr[15] = {1, 3, 3, 5, 8, 10, 11,11, 15, 16, 18, 18, 19, 20, 25}; 



pair<int,int> maxEvent(int l, int r){


    if(arr[r] - arr[l] == Y-1){
        return {arr[l], r-l+1}; 
    }
    
    if(arr[r] - arr[l] < Y-1){
        return {-1,0}; 
    }

    int mid = (r+l)/2; 
    pair<int,int> left = maxEvent(l, mid);
    pair<int,int> right = maxEvent(mid+1, r); 

    if(left.second > right.second) return left; 
    
    return right; 
}; 

int main(){

    pair<int,int> result = maxEvent(0,14); 
    cout << result.second << " " << result.first << " " << result.first+3; 

}