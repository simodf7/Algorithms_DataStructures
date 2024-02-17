#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std; 

// La Stazione Spaziale Internazionale contiene molte centrifughe nei suoi laboratori. 
//Ogni centrifuga avrà un certo numero (C) di camere, ognuna delle quali può contenere 0, 1 o 2 campioni.
// Dovete scrivere un programma che assegni tutti i campioni S alle camere,
// in modo che nessuna camera contenga più di 2 campioni. e la seguente espressione per IM BALAN CE sia minimizzata


// CMi è la massa della camera i e viene calcolata sommando le masse dei campioni assegnati alla camera i. assegnati alla camera i.
//AM è la massa media delle camere ed è calcolata dividendo la somma delle masse di tutti i campioni per il numero di camere (C).
// campioni per il numero di camere (C).


//complessità = O(n^2)

int N = 2; // chamber
int S = 3; // campioni

vector<int> campioni = {6,3,8}; 
int mass[2] = {0,0};

vector<vector<int>> chambers(N, vector<int>(S, -1)); 

int main(){

    sort(campioni.begin(), campioni.end(), greater<int>()); 


    for(int i=0; i<S; i++){ // inseriamo i campioni dal piu grande al piu piccolo nella chamber a massa piu piccola

        int massa_minima = 1000; 
        int chamber_minima = 0; 

        for(int j=0; j<N; j++){
            if(mass[j] < massa_minima){
                massa_minima = mass[j]; 
                chamber_minima = j; 
            }  
        }

        chambers[chamber_minima].push_back(campioni[i]); 
        mass[chamber_minima] += campioni[i];   

    }


    // calcolo imbalance

    int sum = 0; 
    float average = 0;

    for(auto elem: campioni){
        elem += sum; 
    }

    average = sum/N; 

    sum = 0; 
    float imbalance = 0; 

    for(int i=0; i<N; i++){
        for(auto elem: chambers[i]){
            sum += elem; 
        }
        imbalance += abs(sum - average); 
    }

    // stampa elementi e imbalance

    for(int i=0; i<N; i++){
        cout << i << ": "; 
        for(auto elem: chambers[i]){
            if(elem == -1) continue;
            cout << elem << " ";  
        }
        cout << endl; 
    }
    
    cout << "Imbalance: " << imbalance << endl; 

    return 1; 
}

