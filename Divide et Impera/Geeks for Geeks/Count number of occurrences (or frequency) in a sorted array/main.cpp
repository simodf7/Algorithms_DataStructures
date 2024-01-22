#include <iostream>

using namespace std;

int N, x; 
int arr[100]; 

int firstOccurence(){

    int l = 0;
    int r = N-1; 
    int m; 
    int res = -1; 

    while(l<=r){

        m = (r+l)/2;

        if(arr[m] == x){
            res = m; 
            r = m-1; 
        }
        else if(arr[m] < x){
            l = m+1; 
        }
        else{
            r = m-1; 
        }

    }

    return res; 

}

int lastOccurence(){

    int l = 0;
    int r = N-1; 
    int m; 
    int res = -1; 

    while(l<=r){

        m = (r+l)/2;

        if(arr[m] == x){
            res = m; 
            l = m+1; // right
        }
        else if(arr[m] < x){
            l = m+1; // right
        }
        else{
            r = m-1; // left
        }

    }

    return res; 

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

        int lower, upper; 
        lower = firstOccurence(); 
        if(lower == -1){
            cout << "Case#" << i << " :" << x << " doesnt occur in arr \n";   
        }else{
            upper = lastOccurence(); 
            cout << "Case#" << i << " :" << upper-lower +1 << "\n"; 
        }

        ++i; 
        

    }

    return 1; 
}