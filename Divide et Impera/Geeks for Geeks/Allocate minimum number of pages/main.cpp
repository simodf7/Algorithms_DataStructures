#include <iostream>

using namespace std; 


// non va bene, non ho fatto dipendere da m 
// vedi soluzione da geeks for geeks 

int n,m; 
int a[10000]; 


int sum(int m){

    int sum1 = 0; 
    int sum2 = 0; 

    for(int i=0; i<m; i++){
        sum1 += a[i]; 
    }

    for(int i=m; i<n; i++){
        sum2 += a[i]; 
    }

    if(sum1 >= sum2) return sum1; 

    return sum2; 

}



int solve(){

    int res = 1000000; 
    int l = 0;
    int r = n-1; 
    int s; 
    int mid; 

    while(l<=r){

        mid = (r+l)/2; 
        s = sum(mid); 
        if(s < res){
            res = s; 
            l = mid+1; 
        }
        else{
            r = mid-1; 
        }
        

    }

    return res; 


}; 


int main(){

    ios::sync_with_stdio(0); 
    cin.tie(0); 
    
    int t, i=1; 
    
    cin >> t; 
    
    while(t--){
        cin >> n >> m; 
        
        for(int i=0; i<n; ++i){
            cin >> a[i];  
        }


        cout << "Case#" << i << ": " << solve() << "\n";  
        ++i; 
    }




    return 1; 
}