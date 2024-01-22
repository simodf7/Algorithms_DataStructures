#include <iostream>
#include <vector>

using namespace std; 

int N; 

string c[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs","tuv","wxyz"};
int arr[10]; 
string ds; 

//arr[2] = {2,3}; 

void backtrack(int index){

    if(index == N){
        cout << ds << " "; 
        return; 
    }

    
    string s = c[arr[index]-2]; 
    for(int j=0; j<s.size(); j++){
        ds.push_back(s[j]); 
        backtrack(index+1); 
        ds.pop_back(); 
    }




}


int main(){

    ios::sync_with_stdio(0); 
    cin.tie(0); 

    int T, i=1; 

    cin >> T; 

    while(T--){

        cin >> N; 

    
        for(int i=0; i<N; i++){
            cin >> arr[i]; 
        }

        cout << "Case #" << i << ": "; 
        backtrack(0); 
        cout << "\n";
        ++i; 

    }

    return 1; 
}