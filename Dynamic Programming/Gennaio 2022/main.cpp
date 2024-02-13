#include <iostream>
using namespace std; 

int N, T, M;
int times[100];  


// BOH

// N = 2
// T = 10
// M = 3
// int times[3] = 10 30 40

int f(int index, int time){

    if(index == M){
        return 0; 
    }

    // take car 
    if(index == 0){
        int t = times[index]; 
        int take_car = t + 2*T + f(index+1, t+2*T); 
        int not_take_car = times[index] + f(index+1); 
    }

    int take_car = 


    return min(take_car, not_take_car);     
}; 


int main(){

    ios::sync_with_stdio(0); 
    cin.tie(0); 

    int C, i=1;

    cin >> C;


    while(C--){

        cin >> N >> T >> M; 

        for(int i=0; i<M; i++){
            cin >> times[i]; 
        }

        cout << "Case#" << i << ": " <<  f(0, 0) << endl; 
        ++i; 

    }


    return 1; 
}