#include <iostream>
#include <algorithm>

using namespace std; 

int arr[20]; 
int N, K; 


int count(int m){

    int c = 0; 
    for(int i=0; i<N; i++){
        if(arr[i] >= m){
            c++; 
        }
    }

    return c; 
}


int solve(){

    int l = 10000;
    int h = -1; 

    for(int i=0; i<N; i++){
        l = min(l, arr[i]); 
        h = max(h, arr[i]); 
    }

    while(l<h){

        int m = (l+h)/2; 

        if(count(m) > K){
            l = m+1; 
        }
        else if (count(m) == K){
            return m; 
        }
        else{
            h = m; 
        }

        // if(count(m) > K){
        //     l = m+1; 
        // }
        // else{
        //     h = m; 
        // }

    }

    return h; 

}


int main(){

    ios::sync_with_stdio(0); 
    cin.tie(0); 


    int T, i=1; 
    cin >> T; 

    while(T--){

        cin >> N >> K; 

        for(int i=0; i<N; i++){
            cin >> arr[i]; 
        }

        cout << "Case #" << i << ": " << solve() << "\n"; 
        ++i; 

    }

}