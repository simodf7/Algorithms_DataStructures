#include <iostream> 
using namespace std; 


int N,x; 
int arr[100]; 

int solve(){

    int l = 0; 
    int r = N-1; 

    int m, current, res; 
    int diff = 1000; 


    while(l<=r){

        m = (r+l)/2;
        current = arr[m]-x;

        if(abs(current) < diff){
            diff = abs(current); 
            res = m; 
        } 

        if(current > 0){
            r = m-1; // left
        }
        else if(current == 0){
            return arr[m]; 
        }
        else{
            l = m+1; // right
        }


    }

    return arr[res]; 
}



int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    int T, i=1; 

    cin >> T; 


    while(T--){

        cin >> N >> x; 

        for(int i=0; i<N; i++){
            cin >> arr[i]; 
        }

        cout << "Case#" << i << ": " << solve() << "\n";  
        ++i; 

    }

    return 1; 
}