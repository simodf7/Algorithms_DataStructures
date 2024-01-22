#include <iostream>
using namespace std; 

int N = 32; 
int arr[32]; 

int count1bit(int l, int r){

    if(l==r){
        if(arr[l] == 1){
            return 1; 
        }
        return 0; 
    }

    int m = (r+l)/2;

    int left_count = count1bit(l, m); 
    int right_count = count1bit(m+1, r); 

    return left_count + right_count; 
}

int main(){

    ios::sync_with_stdio(0); 
    cin.tie(0); 

    int T, i=1; 

    cin >> T;

    while(T--){

        for(int i=0; i<N; i++){
            cin >> arr[i]; 
        }

        cout << "Case#" << i << ": " << count1bit(0,N-1) << "\n"; 
        ++i; 

    }


    return 1; 
}