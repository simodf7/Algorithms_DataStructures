#include <iostream> 

using namespace std; 

int N, M, K; 
int arr[100], arr2[100]; 

int solve(){
 
    int i=0, j = 0, k = 0; 
    int res; 

    while(i<N && j<M && k<K){

        if(arr[i] < arr2[j]){
            res = arr[i]; 
            i++;
        }
        else{
            res = arr2[j]; 
            j++; 
        }

        k++; 

    }

    while(i<N && k<K){
        res = arr[i]; 
        k++; 
    }
   
    while(j<M && k<K){
        res = arr2[j]; 
        k++; 
    }

    return res; 


}


int main(){

    ios::sync_with_stdio(0); 
    cin.tie(0);

    int T, i=1; 
    cin >> T; 

    while(T--){

        cin >> N >> M >> K; 

        for(int i=0; i<N; i++){
            cin >> arr[i]; 
        }

        for(int i=0; i<M; i++){
            cin >> arr2[i]; 
        }


        cout << "Case#" << i << ": " << solve() << "\n";  
        ++i; 
    }


    return 1; 
}