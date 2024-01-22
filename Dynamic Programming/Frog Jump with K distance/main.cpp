#include <iostream>

using namespace std; 
int height[5] = {10,40,50,20,60};
int k = 3;  


int minimalEnergy(int n){

    if(n==0){
        return 0; 
    }


    int energy = 10000; 
    for(int i=1; i<=k; i++){
        if(n-i >= 0){
            energy = min(energy, abs(height[n] - height[n-i]) + minimalEnergy(n-i));
        }
    }

    return energy; 

}

int main(){

    cout << minimalEnergy(5);


    return 1; 
}