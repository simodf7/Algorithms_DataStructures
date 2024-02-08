#include <iostream>
#include <vector>
using namespace std; 


// Given an array ‘ARR’, partition it into two subsets (possibly empty) such that their union is the original array. 
// Let the sum of the elements of these two subsets be ‘S1’ and ‘S2’.

// Given a difference ‘D’, count the number of partitions in which ‘S1’ is greater than or equal to ‘S2’ 
// and the difference between ‘S1’ and ‘S2’ is equal to ‘D’. Since the answer may be too large, return it modulo ‘10^9 + 7’.

// If ‘Pi_Sj’ denotes the Subset ‘j’ for Partition ‘i’. Then, two partitions P1 and P2 are considered different if:

// 1) P1_S1 != P2_S1 i.e, at least one of the elements of P1_S1 is different from P2_S2.
// 2) P1_S1 == P2_S2, but the indices set represented by P1_S1 is not equal to the indices set of P2_S2. 
// Here, the indices set of P1_S1 is formed by taking the indices of the elements from which the subset is formed.
// Refer to the example below for clarification.

// Note that the sum of the elements of an empty subset is 0.
// For example :

// If N = 4, D = 3, ARR = {5, 2, 5, 1}
// There are only two possible partitions of this array.
// Partition 1: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
// Partition 2: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
// These two partitions are different because, in the 1st partition, S1 contains 5 from index 0, and in the 2nd partition, S1 contains 5 from index 2.

int arr[4] = {5, 2, 5, 1};
int D = 3; 


int countSubset(int index, int target, vector<vector<int>>& dp){

    if(target == 0){
        return 1; 
    }

    if(index == 0){
        if(target == arr[0]){
            return 1; 
        }
        return 0; 
    }

    if(dp[index][target] != -1){
        return dp[index][target];
    }

   
    int take = 0; 

    if(target >= arr[index] ){
        take = countSubset(index-1, target - arr[index], dp) ; 
    }
    int not_take = countSubset(index-1, target, dp) ; 


    return dp[index][target] = take + not_take; 
}


int partitions(){

    int sum = 0; 
    for(int i=0; i<4; i++){
        sum += arr[i]; 
    }

    if(sum-D <0) return 0; 
    if((sum-D) %2 == 1) return 0; 

    int s2 = (sum-D)/2; 

    vector<vector<int>> dp(4, vector<int>(s2+1, -1));
    return countSubset(3, s2, dp);
}



// BENE ma non benissimo
// int partitions(int index, int sum1, int sum2){ 

//     if(index < 0){
//         if(sum1 - sum2 == D) return 1; 
//         return 0; 
//     }

    
    

//     int take_1 = partitions(index-1, sum1+arr[index], sum2); 
//     int take_2 = partitions(index-1, sum1, sum2+arr[index]); 


//     return take_1 + take_2; 

// }




int main(){

    cout << partitions(); 
    return 1; 
}