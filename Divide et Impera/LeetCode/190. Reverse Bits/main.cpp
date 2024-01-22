#include <iostream>
#include <math.h>

using namespace std; 

int N = 32; 
int arr[32]; 

void swap(int x, int y){
    
    int temp = arr[x]; 
    arr[x] = arr[y]; 
    arr[y] = temp; 
}

int solve(){

    int i=0; 
    while(i < N/2){
        swap(i, N-i-1); 
        i++; 
    }   



    int sum = 0; 
    for(int i=0; i<N; i++){
        if(arr[N-i-i] == 1){
            sum += pow(2.0, i/1.0); 
        }
    }


    return sum; 

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



       cout << "Case#" << i << ": "  << solve() << "\n"; 
        ++i; 
 

    }



    return 1; 
}