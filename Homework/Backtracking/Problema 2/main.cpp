#include <iostream>
#include <fstream>
#include <bitset>


using namespace std;

int ans,n;


bitset<30> riga, diag_s, diag_d;

void backtrack(int j){
    if(j == n){
        ans++;
        return;
    }
    for(int i = 0; i<n; i++){
        if(!riga[i] && !diag_s[i+j] && !diag_d[i-j+n-1]){
            riga[i] = diag_s[i+j] = diag_d[i-j+n-1] = true;
            backtrack(j+1);
            riga[i] = diag_s[i+j] = diag_d[i-j+n-1] = false;
        }
    }
}

int main(){
    ifstream file("input2.txt");

    int t;
    file>>t;

    while(t--){
        ans = 0;
        file>>n;
        backtrack(0);
        cout<<ans<<"\n";
    }
}


//complessità temporale : O(n!)