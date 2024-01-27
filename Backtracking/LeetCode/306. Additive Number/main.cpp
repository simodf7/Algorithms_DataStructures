#include <iostream>

using namespace std; 

string num = "1158"; 

// Input: "112358"
// Output: true
// Explanation: 
// The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
// 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8

// Input: "199100199"
// Output: true
// Explanation: 
// The additive sequence is: 1, 99, 100, 199. 
// 1 + 99 = 100, 99 + 100 = 199

// NON FUNZIONA


bool check(string p1, string p2, string c){


    int prev1 = stoi(p1); 
    int prev2 = stoi(p2); 
    int curr = stoi(c); 

    if(prev1 + prev2 != curr) return false; 

    return true;  

}   

bool backtrack(int index, string prev1, string prev2, string current){

    if(index == num.size() && prev1.size() != 0 && prev2.size() != 0 && current.size() != 0){
        return true;
    }

    if(prev1.size() != 0 && prev2.size() != 0 && current.size() != 0){
        if(!check(prev1, prev2,current)) return false; 
    }
    

    if(backtrack(index+1, prev1+num[index], prev2, current)) return true; 

    // take number as prev2
    if(backtrack(index+1, prev1, prev2+num[index], current)) return true; 

    // take number as current
    if(backtrack(index+1, prev1, prev2, current+num[index])) return true; 



    return false; 
}


int main(){

    if(backtrack(0,"", "", "")) cout << "true"; 
    else cout << "false";

    return 1; 
}