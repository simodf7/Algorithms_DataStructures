#include <iostream>

using namespace std; 

// "101023"

string s = "101023"; 


bool check(const string &ds){

    if(ds.size() > 1 && ds[0] == '0') return false; 
    int value = stoi(ds); 
    return value >=0 && value <= 255; 
}

void backtrack(int dots, int index, string current){

    if(dots == -1 && index == s.size()){
        current.erase(current.size()-1);
        cout << current << endl; 
        return; 
    }

    if(dots == -1 || index == s.size()){
        return; 
    }

    
    for(int i=1; i<=3; i++){
        if(index + i > s.size()) break;
        string ds = s.substr(index, i); 
        if(check(ds)){
            backtrack(dots-1, index+i, current + ds + '.'); 
        }

    }



}

int main(){

    backtrack(3,0, ""); 
    return 1; 
}