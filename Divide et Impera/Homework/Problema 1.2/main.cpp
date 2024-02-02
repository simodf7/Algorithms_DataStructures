#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Dato un insieme di stringhe, si implementi un algoritmo divide et impera per trovare il
// prefisso in comune più lungo.

string TrovaPrefisso(const string& s1, const string& s2) {
    int lunghezzaMinima = min(s1.length(), s2.length());
    for (int i = 0; i < lunghezzaMinima; i++) {
        if (s1[i] != s2[i]) {
            return s1.substr(0, i);
        }
    }
    return s1.substr(0, lunghezzaMinima);
}

string TrovaPrefissoComune(vector<string>& V, int p, int r) {
    if (p == r) {
        return V[p];
    } else {
        int q = (p + r) / 2;
        string prefissoSinistra = TrovaPrefissoComune(V, p, q);   // come il merge ma con i confronti
        string prefissoDestra = TrovaPrefissoComune(V, q + 1, r);
        return TrovaPrefisso(prefissoSinistra, prefissoDestra);
    }
}

string TrovaPrefisso(vector<string>& V) {
    if (V.empty()) {
        return "";
    }
    return TrovaPrefissoComune(V, 0, V.size() - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string x;
    int i = 1;
    int n;


    while(cin>>n){
        if (n == 0) break;
        vector<string> V (n);

    for(int j= 0; j<n; j++){
        cin>>x;
        V[j] = x;
    }


    string prefisso = TrovaPrefisso(V);
    cout<<"Test Case #"<<i<<": "<<prefisso<<"\n";
    i++;
    }
}