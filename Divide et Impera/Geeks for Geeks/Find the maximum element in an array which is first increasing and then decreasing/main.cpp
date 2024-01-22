#include <iostream>

using namespace std; 

int N; 
int arr[100];           

int solve(){

    int l = 0; 
    int r = N-1; 
    int m; 

    while(l<=r){

        m = (r+l)/2; 

        if(arr[m] < arr[m+1]){
            l = m+1; 
        }
        else{
            r = m-1; 
        }

    }

    return arr[l]; 

}


int main(){

    ios::sync_with_stdio(0); 
    cin.tie(0); 

    int T, i=1; 

    cin >> T; 
    while(T--){
        cin >> N; 

        for(int i=0; i<N; i++){
            cin >> arr[i]; 
        }
        

        cout << "Case#" << i << ": " << solve() << "\n"; 
        ++i; 
    }



    return 1; 
}