#include <iostream>
#include <vector>
using namespace std; 

// Input: s = "()())()"
// Output: ["(())()","()()()"]

// NON FUNZIONA


string s = "(a)())()";

void backtrack(vector<pair<int, string>>& t, string current, int index, int open, int close, int removals){

    if(index == s.length()){
        if(open == close && current[current.size()-1] != '('){
            if(t.size() == 0) t.push_back({removals, current}); 
            else{
                if(removals < t[0].first) {
                    t.clear(); 
                    t.push_back({removals, current}); 
                }
                else if(removals == t[0].first){
                    t.push_back({removals, current}); 
                }
            }
        }
        return;
    }


    // use bracket 
    if(s[index] == ')') {
        // use it
        backtrack(t, current + s[index], index+1, open, close+1, removals); 
        // dont
        backtrack(t, current, index+1, open, close, removals+1); 
    }
    else if(s[index] == '('){
        backtrack(t, current + s[index], index+1, open+1, close, removals);
        backtrack(t, current, index+1, open, close, removals+1);
    }else{
        backtrack(t, current + s[index], index+1, open, close, removals); 
    }
    



}


void RemoveInvalid(){
    vector<pair<int, string>> result; 
    backtrack(result, "", 0, 0,0, 0); 
    
    for(auto elem: result){
        cout << elem.second << endl; 
    }
}



int main(){


    RemoveInvalid(); 
    return 1; 
}