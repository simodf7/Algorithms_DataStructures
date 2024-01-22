#include <iostream>
using namespace std; 

int N;  

int arr[10];

int sum(int a, int b){

    int s = 0; 
    for(int i=a; i<b; i++){
        s += arr[i]; 
    }

    return s; 
}

int solve(){

    int l = 0; 
    int r = N-1; 
    int m; 

    while(l>=r){

        int m = (r+l)/2; 

        



    }



}

int main(){

    ios::sync_with_stdio(0); 
    cin.tie(0); 

    int T, i=1; 
    cin >> T; 

    while(T--){

        cin >> N; 


        for(int i=0; i<N; i++){
            cin >> a[i]; 
        }
        


        cout << "Case#" << i << ": " << solve() << "\n"; 
        ++i;
    }



    return 1; 
}