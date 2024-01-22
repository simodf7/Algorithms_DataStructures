#include <iostream>
using namespace std; 

int N, M; 

int a[10];
int b[10]; 
int c[10]; 

float solve(){

    int i=0; 
    int j=0; 
    int k=0; 

    while(i<N && j<M){

        if(a[i] > b[j]){
            c[k] = b[j]; 
            j++;
        }else{
            c[k] = a[i]; 
            i++; 
        }
        k++; 
    }

    while(i<N){
        c[k] = a[i]; 
        i++; 
        k++; 
    }

    while(j<M){
        c[k] = b[j]; 
        j++; 
        k++; 
    }

    int dim = N+M; 
    if(dim %2 == 0){
        return (c[dim/2] + c[dim/2 -1])/2.0; 
    } 
    
    return c[dim/2]; 


}

int main(){

    ios::sync_with_stdio(0); 
    cin.tie(0); 

    int T, i=1; 
    cin >> T; 

    while(T--){

        cin >> N >> M; 


        for(int i=0; i<N; i++){
            cin >> a[i]; 
        }
        
        for(int i=0; i<M; i++){
            cin >> b[i]; 
        }

        cout << "Case#" << i << ": " << solve() << "\n"; 
        ++i;
    }



    return 1; 
}