#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int massimo_numero_citta(const string& seq1, const string& seq2, int pos1, int pos2, vector<vector<int>>& memo) {
    if (pos1 >= seq1.length() || pos2 >= seq2.length()) {
        return 0;
    }

    if (memo[pos1][pos2] != -1) {
        return memo[pos1][pos2];
    }

    int count = 0;
    if (seq1[pos1] == seq2[pos2]) {
        count = 1 + massimo_numero_citta(seq1, seq2, pos1 + 1, pos2 + 1, memo);
    }

    count = max(count, max(massimo_numero_citta(seq1, seq2, pos1 + 1, pos2, memo),
                           massimo_numero_citta(seq1, seq2, pos1, pos2 + 1, memo)));

    memo[pos1][pos2] = count;
    return count;
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

        vector<vector<int>> memo(seq1.length(), vector<int>(seq2.length(), -1));
        int max_citta = massimo_numero_citta(seq1, seq2, 0, 0, memo);
        cout << "Caso #" << caso << ": numero massimo = " << max_citta << endl;

        ++caso;
    }

    return 0;
}