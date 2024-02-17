#include <iostream>
#include <algorithm>
using namespace std; 


// PROBLEMA 2
// Dato un array di N interi, si implementi un algoritmo che, in tempo logaritmico, determina se un
// numero dato in ingresso x appare più di N/2 volte nell'array.
// INPUT
// La prima riga riporta il numero di casi di test T. Seguono T casi di test, ciascuno descritto da tre righe:
// la prima riporta la dimensione N dell’array; la second riporta gli N elementi dell’array; la terza riporta
// l’input x.
// OUTPUT
// Per ogni caso di test, l’algoritmo stampi TRUE se x appare più di N/2 volte o FALSE altrimenti.
// Sample Input
// 
// 7
// 1 2 3 3 3 3 10
// 3


// E' una ricerca binaria quindi O(logn)

int N, x; 
int arr[100]; 

int firstOccurence(){

    int l = 0;
    int r = N-1; 
    int m; 
    int res = -1; 

    while(l<=r){

        m = (r+l)/2;

        if(arr[m] == x){
            res = m; 
            r = m-1; 
        }
        else if(arr[m] < x){
            l = m+1; 
        }
        else{
            r = m-1; 
        }

    }

    return res; 

}

int lastOccurence(){

    int l = 0;
    int r = N-1; 
    int m; 
    int res = -1; 

    while(l<=r){

        m = (r+l)/2;

        if(arr[m] == x){
            res = m; 
            l = m+1; // right
        }
        else if(arr[m] < x){
            l = m+1; // right
        }
        else{
            r = m-1; // left
        }

    }

    return res; 

}



int main(){

    ios::sync_with_stdio(0); 
    cin.tie(0);  

    int T, i=1; 

    cin >> T; 

    while(T--){

        cin >> N; 


        for(int i=0; i<N; i++){
            cin >> arr[i]; 
        }

        cin >> x; 

        int lower, upper; 
        lower = firstOccurence(); 
        upper = lastOccurence(); 
        cout << "Case#" << i << " : ";   

        if(upper - lower +1 > N/2){
            cout << "TRUE" << endl; 
        }else{
            cout << "FALSE" << endl; 
        }

        ++i; 
        

    }

    return 1; 
}

