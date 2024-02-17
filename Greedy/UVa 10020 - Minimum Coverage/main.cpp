#include <iostream>
#include <algorithm>

using namespace std;


//per ogni elemento mi vado a cercare quello che ha lato sinitro minore o uguale alla posizione
//raggiunta attualmente e lato destro maggiore possibile

//complessità = o(n^2) nel caso peggiore

bool smaller(pair<int,int>a, pair<int,int>b){return a.first<b.first;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test,m;

    pair<int,int>v[100];

    cin>>test;
    while(test--){
        cin>>m;
        int size = 0;
        while(1){
            cin>>v[size].first>>v[size].second;
            if(v[size].first == 0 && v[size].second == 0)break;
            size++;
        }
        sort(v,v+size,smaller);

        int current_l = 0, right_reach = 0, j;

        pair<int,int> segments[50];

        while(right_reach < m){
            int new_l = 0;
            int pos = -1;
            j = 0;
            for(int i = 0; i<size; i++){
                if(v[i].first>current_l)break;
                else if(v[i].second>new_l){
                    new_l = v[i].second;
                    pos = i;
                }
            }
            if(pos == -1) break;
            segments[j] = v[pos];
            j++;
            current_l = right_reach = new_l;
        }
        if(right_reach >= m){
            cout<<j<<"\n";
            for(int i = 0; i<j; i++){
                cout<<segments[i].first<<" "<<segments[i].second<<"\n";
            }
        }
        else cout<<"0"<<"\n";
    }
    return 0;
}
