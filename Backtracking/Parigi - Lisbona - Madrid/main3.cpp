#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int massimo_numero_citta(const string& seq1, const string& seq2, vector<vector<int>>& memo) {
    int len1 = seq1.length();
    int len2 = seq2.length();

    for (int i = 0; i <= len1; ++i) {
        for (int j = 0; j <= len2; ++j) {
            if (i == 0 || j == 0) {
                memo[i][j] = 0;
            } else if (seq1[i - 1] == seq2[j - 1]) {
                memo[i][j] = 1 + memo[i - 1][j - 1];
            } else {
                memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
            }
        }
    }

    return memo[len1][len2];
}

int main() {
    int caso = 1;

    while (true) {
        string seq1;
        getline(cin, seq1);

        if (seq1[0] == '#') {
            break;
        }

        string seq2;
        getline(cin, seq2);

        int len1 = seq1.length();
        int len2 = seq2.length();
        
        vector<vector<int>> memo(len1 + 1, vector<int>(len2 + 1, 0));

        int max_citta = massimo_numero_citta(seq1, seq2, memo);
        cout << "Caso #" << caso << ": numero massimo = " << max_citta << endl;

        ++caso;
    }

    return 0;
}