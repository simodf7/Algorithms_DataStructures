#include <iostream>
#include <vector>
using namespace std;

int arr[2] = {0,0}; 

void backtrack(int index){

    if(index == -1){
        for(int i=0; i<2;i++){
            cout << arr[i]; 
        }
        cout << endl; 
        return; 
    }


    // non cambia
    backtrack(index-1); 

    // cambia
    if(arr[index] == 0) {
        arr[index] = 1;
    }else arr[index] = 0; 

    backtrack(index-1);
 

}

int main() {
   
    backtrack(1); 
 
    return 0;
}

