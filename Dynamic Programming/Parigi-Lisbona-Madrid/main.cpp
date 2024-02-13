#include <iostream>
using namespace std; 

// PROBLEMA
// Devi partire per una vacanza, e devi decidere quali città visitare. Tua madre dice “Figlio mio, DEVI
// visitare Parigi, Madrid, Lisbona e Londra. Ma è divertente solo se lo fai in quest’ordine.” Poi tuo
// padre dice: “Figlio, se hai intenzione di viaggiare, vai prima a Parigi, poi a Lisbona, poi a Londra e
// poi, finalmente, vai a Madrid. Fidati!".
// Vorresti provare a seguire i loro suggerimenti nel miglior modo possibile. Quindi, ti rendi conto che
// l'ordine "Parigi-Lisbona-Londra" è quello che soddisfa meglio sia tua madre che tuo padre. Potrai
// poi dire che non hai potuto visitare Madrid, anche se ti sarebbe piaciuto molto.
// Se tuo padre avesse suggerito "Londra-Parigi-Lisbona-Madrid", allora avresti avuto due
// ordinamenti, "Parigi-Lisbona" e "Parigi-Madrid", che avrebbero soddisfatto al meglio entrambi i
// suggerimenti dei tuoi genitori. In questo caso, avresti potuto visitare solo 2 città.
// Si scriva un programma per risolvere questo problema.
// Per semplicità, si supponga di rappresentare ogni città con un carattere, utilizzando lettere
// maiuscole, lettere minuscole, cifre e lo spazio. Quindi, si possono avere al massimo 63 città diverse
// da visitare. E’ possibile visitare una città più di una volta.
// Ad esempio, se Parigi è rappresentata con 'a', Madrid con 'b', Lisbona con 'c' e Londra con 'd', allora
// il suggerimento di tua madre sarebbe 'abcd' e il suggerimento di tuo padre sarebbe 'acdb' (o 'dacb',
// nel secondo esempio).
// Il programma legge due sequenze di viaggio e deve fornire il numero massimo di città visitabili in
// modo da soddisfare al meglio i suggerimenti di entrambi i genitori.

// Sample Input
// abcd
// acdb
// abcd
// dacb
// #
// Sample Output
// Caso #1: numero massimo = 3
// Caso #2: numero massimo = 2

string s1 = "abcd";
string s2 = "acdb";


int maxCities(int i, int j){

    if(i<0 || j<0){
        return 0; 
    }


    if(s1[i] == s2[j]){
        return 1 + maxCities(i-1, j-1); 
    }

    return max(maxCities(i-1, j), maxCities(i, j-1)); 

}


int main(){

    cout << maxCities(s1.size()-1,s2.size()-1)<< endl;  
    return 1; 


}