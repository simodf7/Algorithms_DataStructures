#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

int v[100];
int dim;


int solve(){
    int max_sum = 0;
    int curr_max = 0;
    for(int i = 0; i<dim; i++){
        curr_max = max(v[i], curr_max+v[i]);
        max_sum = max (max_sum, curr_max);
    }
    return max_sum;
}


int main(){
    fstream file("input1.txt");


    string in;
    int x;

    while(getline(file,in)){

        if(in == "END")break;
        dim = 0;

        stringstream input(in);

        while(input>>x){
            v[dim] = x;
            dim++;
        }

        int ans = solve();
        cout<<ans<<"\n";
    }
}

//complessità temporale : O(n) , scorro il vettore di elementi una sola volta