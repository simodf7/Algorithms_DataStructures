#include <iostream>

using namespace std;

int m,n; 
int a[5][5] = {
    1,4,7,11,15, 
    2,5,8,12,19,
    3,6,9,16,22,
    10,13,14,17,24
}; 

bool search(int value){

   int r = 0; 
   int c = n-1; 

   while(r<m && c >=0) {
        if(a[r][c] == value){
            return true; 
        }
        else if(a[r][c] < value){
            r++; 
        }
        else{
            c--; 
        }

   }

    return false; 

}


int main(){

    if(search(23)){
        cout << "Trovato" << endl;
    }
    else cout << "Non Trovato" << endl; 


    return 1; 
}