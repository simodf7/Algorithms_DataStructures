#include <iostream>

using namespace std; 




int solve(int i){ // we need to find k using binary search

    int l = 1; 
    int r = i;
    int mid = 0; 
    int length = 0; 

    while (l<r){

        mid = (r+l)/2; 
        length = mid*(mid+1)/2; 
        if( length < i ){
            l = mid +1;
        }
        else {
            r = mid; 
        }


    }

    // i-10-4 = 8-6 = 2
    // i-3-2 = 3
    length = l*(l+1)/2;
    return i-(length - l); 
    
}



int main(){
    
    cout << solve(8) << endl;
    cout << solve(3) << endl;


    return 1; 
}