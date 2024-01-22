#include <iostream>

using namespace std; 


int m,n; 
int a[10000], b[10000]; 


float solve(){

    int dim = m+n; 
    int c[dim]; 

    int k=0, i=0, j=0;

    while(i<m && j<n){
        if(a[i] < b[j]){
            c[k] = a[i];  
            i++; 
        }else{
            c[k] = b[j];
            j++; 
        }
        k++; 
    }

    while(i<m){
        c[k] = a[i]; 
        i++; 
    }

    while(j<n){
        c[k] = b[j]; 
        j++; 
    }


    if(dim % 2 == 0) return (c[dim/2] + c[dim/2 + 1])/2; 

    return c[dim/2]; 


}


int main(){

    ios::sync_with_stdio(0); 
    cin.tie(0); 
    
    int t, i=1; 
    
    cin >> t; 
    
    while(t--){
        cin >> m >> n; 
        
        for(int i=0; i<m; ++i){
            cin >> a[i];  
        }

        for(int i=0; i<n; ++i){
            cin >> b[i];  
        }


        cout << "Case#" << i << ": " << solve() << "\n"; 
        ++i; 
    }




    return 1; 
}