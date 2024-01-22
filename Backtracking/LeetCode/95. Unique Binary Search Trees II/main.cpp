#include <iostream>
#include <vector>

// NON FUNZIONA

using namespace std; 
vector<int> ds; 
int used[3] = {0,0,0};


void backtrack(int nodes, int last){

    if(nodes == 0){
        for(auto elem: ds){
            cout << elem << " "; 
        }
        cout << endl;
        return; 
    }


    for(int i=1; i<=3; i++){

        if(nodes != 3 &&  i > last && used[i-1] != 1) {
            ds.push_back(0);   // mettiamo null
        }

        if(used[i-1] != 1){
            used[i-1] = 1; 
            ds.push_back(i); 
            last = i; 
            backtrack(nodes-1, last); 
            used[i-1] = 0; 
            if(ds.back() == 0 && ds.size() != 0) ds.pop_back();
            ds.pop_back(); 
            
        }
        
    }

}


int main(){

    backtrack(3,0);

    return 1; 
}