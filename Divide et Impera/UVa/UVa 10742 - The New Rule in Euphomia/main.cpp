#include <iostream>
using namespace std; 


// no

int countWays(int coins_used, int current_coint, int amount){

    if(coins_used == 2 && amount == 0){
        return 1;
    }

    if(coins_used > 2 || amount <0){
        return 0;   
    }


    if(current_coint == 1){
        int old_coin = countWays(coins_used, current_coint, amount-current_coint);
    }
    else{
        int old_coin = countWays(coins_used+1, current_coint-1, amount-(current_coint-1)); 
    }
   


    return countWays(coins_used, current_coint, amount-current_coint) + countWays(coins_used+1,current_coint+1,amount-(current_coint-1));
}


int main(){

    countWays(0,1,10); 

    return 1; 
}