#include <iostream>
using namespace std;


string ds; 

void backtrack(int open, int close){

    if(open == 0 && close == 0){
        cout << ds << endl; 
    }

    if(open < 0 || close < 0 || open > close) {
        return; 
    }

    
    // parentesi sinistra
    ds.push_back('(');
    backtrack(open-1, close); 
    ds.pop_back();

    // parentesi destra
    ds.push_back(')'); 
    backtrack(open, close-1);  
    ds.pop_back(); 
    

}

int main(){


    backtrack(3,3); 
    return 1; 
}