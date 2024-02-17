#include <iostream>
#include <vector>
using namespace std; 


// Your job is to find out in how many ways one could pay a certain price using a limited number of
// coins (Note that the number of coins paid is limited but not the value or source. I mean there was
// infinite number of coins of all values). For example, by using three coins one can pay six dollars in 3
// ways, 1+1+4, 1+2+3, and 2+2+2. Similarly, one can pay 6 dollars using 6 coins or less in 11 ways.
// Input
// The input file contains several lines of input. Each line of input may contain 1, 2 or 3 integers. The
// first integer is always N (0 ≤ N ≤ 300), the dollar amount to be paid. All other integers are less than
// 1001 and non-negative.
// Output
// For each line of input you should output a single integer.
// When there is only one integer N as input, you should output in how many ways N dollars can be
// paid.
// When there are two integers N and L1 as input, then you should output in how many ways N
// dollars can be paid using L1 or less coins.
// When there are three integers N , L1 and L2 as input, then you should output in how many ways
// N dollars can be paid using L1, L1 + 1, . . . , L2 coins (summing all together). Remember that L1 is not
// greater than L2.
// Sample Input
// 6
// 6 3
// 6 2 5
// 6 1 6
// Sample Output
// 11
// 7
// 9
// 11


int dollars = 6; 


int countWays(int coin_min, int coin, int d){

    if(d == 0){
        return 1; 
    }

    if(coin == 1){
        return 1; 
    }

    if(coin == coin_min){
        if(d % coin_min) return 1;
    }

    
    int take = 0; 
    if(d - coin >= 0){
        take = countWays(coin_min, coin, d-coin); 
    }

    int not_take = countWays(coin_min, coin-1, d); 

    return take + not_take; 
}





int main(){

   cout << countWays(1, dollars, dollars) << endl; 
   cout << countWays(1, 3, dollars) << endl; 
   cout << countWays(2, 5, dollars) << endl; 
   cout << countWays(1, 6, dollars) << endl; 

   return 1; 


}