#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
// Funzione per verificare se una parte della stringa è un valido campo IP
bool isValid(const string &s) {
    if (s.size() > 1 && s[0] == '0') return false; // No leading zeros
    if (s.size() > 3) return false; // Lunghezza massima di 3 cifre
    int val = stoi(s);
    return val >= 0 && val <= 255;
}
 
// Utilizzo del backtracking per generare tutti gli indirizzi IP validi
void backtrack(const string &s, int start, int part, string current, vector<string> &result) {
    if (part == 4 && start == s.size()) { // Se abbiamo 4 parti e abbiamo esaurito la stringa
        result.push_back(current.substr(0, current.size() - 1)); // Rimuovere l'ultimo punto
        return;
    }
    if (part == 4 || start == s.size()) return; // Condizioni di terminazione
 
    for (int i = 1; i <= 3 && start + i <= s.size(); ++i) {
        string substring = s.substr(start, i);
        if (isValid(substring)) {
            backtrack(s, start + i, part + 1, current + substring + ".", result);
        }
    }
}
 
vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    backtrack(s, 0, 0, "", result);
    return result;
}
 
int main() {
    string s = "25525511135";
    vector<string> validIPs = restoreIpAddresses(s);
 
    for (const string &ip : validIPs) {
        cout << ip << endl;
    }
 
    return 0;
}