// print all subsets without duplicate

#include <iostream>
#include <vector>

using namespace std; 

int arr[6] = {1,2,2,3,3,3}; 
vector<int> ds; 

void backtrack(int index){

    if(ds.size() == 0) cout << "{} \n"; 
    else {
        for(auto elem: ds){
                cout << elem << " "; 
            }
        cout << endl; 
    }

    

    if(index == 6){
        return; 
    }

    for(int i=index; i<6; i++){
        if(i != index && arr[i] == arr[i-1]) continue; 
        ds.push_back(arr[i]);  // pick i-th element
        backtrack(i+1); 
        ds.pop_back(); // undo for picking the next
    }

}

int main(){

    // sorting prima
    backtrack(0); 


    return 1; 
}
