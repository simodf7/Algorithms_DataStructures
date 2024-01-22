#include <iostream>
#include <vector>


// qualcosa non va
using namespace std; 

int M = 3; 
string s ="aab";
vector<string> ds; 
string w; 

bool isPalindrome(string word){

    int dim = word.size(); 
    for(int i=0; i<dim/2; i++){
        if(word[i] != word[dim-i-1]) return false; 
    }

    return true; 

}



void backtrack(int index){

    if(index == s.size()){
        for(auto elem: ds){
            cout << elem << " "; 
        }
        cout << endl; 
        return; 
    }


    for(int i=index; i<s.size(); i++){
        w = s.substr(index, i - index +1 ); 
        if(isPalindrome(w)){
            ds.push_back(w); 
            backtrack(index+1);
            ds.pop_back(); 
        }
    }

   

}


int main (){

    backtrack(0); 


    return 1; 
}