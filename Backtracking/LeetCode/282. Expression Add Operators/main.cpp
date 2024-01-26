#include <iostream>
#include <vector>


using namespace std;


int target = 8; 
string s = "232";


// 0 1 
// 1*2

void backtrack(int count, int index, string current, int prev){


    if(index == 3){
        if(count == target){
            cout << current << endl; 
        }
        return; 
    }

    int currentNum = int(s[index] - '0'); 
    
    if(index == 0){
        backtrack(count + currentNum, index +1, current + s[index], currentNum);
    }
    else{
        backtrack(count + currentNum, index +1, current + "+" + s[index], currentNum); 
        backtrack(count - currentNum, index +1, current + "-" + s[index], -currentNum); 
        // moltiplicazione piu complicata
        backtrack(count - prev + prev * currentNum, index +1, current + "*" + s[index], prev * currentNum); 
    }


     


}



int main(){


    backtrack(0,0, "", 0);
    return 1; 
}