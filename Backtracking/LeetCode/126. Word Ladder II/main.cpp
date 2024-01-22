#include <iostream>
#include <vector>
using namespace std;


string beginWord = "hit";
string endWord ="cog"; 
vector<string> dict = {"hot","dot","dog","lot","log","cog"};
vector<string> ds; 
int used[6] = {0,0,0,0,0,0};

bool isValid(string c, string t){

    int count = 0; 
    for(int i=0; i<t.size(); i++){
        if(c[i] != t[i]) count++; 
        if(count > 1) return false; 
    }

    return true; 

}

int backtrack(string current){

    if(current == endWord){
        for(auto elem: ds){
            cout << elem << " "; 
        }
        cout << endl; 
        return ds.size(); 
    }


    for(int i=0; i<dict.size(); i++){
        if(isValid(current, dict[i]) && used[i] != 1){
            used[i] = 1;  
            ds.push_back(dict[i]); 
            backtrack(dict[i]); 
            ds.pop_back(); 
            used[i] = 0; 
        }
    }


}





int main(){

    ds.push_back(beginWord);
    backtrack(beginWord);

    return 1; 
}