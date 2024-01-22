#include <iostream>
#include <vector>

using namespace std;

bool isSameList(int color1, int color2, const vector<vector<int>>& colorLists) {
    for (const auto& lst : colorLists) {
        if (find(lst.begin(), lst.end(), color1) != lst.end() &&
            find(lst.begin(), lst.end(), color2) != lst.end()) {
            return true;
        }
    }
    return false;
}

int backtrack(int index, int currentSegment, const vector<vector<int>>& colorLists, vector<bool>& visited) {
    if (index == visited.size()) {
        return 1;  // Found a new segment
    }

    int count = 0;

    for (int i = index; i < visited.size(); ++i) {
        if (!visited[i]) {
            if (currentSegment == -1 || !isSameList(currentSegment, i, colorLists)) {
                visited[i] = true;
                count += backtrack(i + 1, i, colorLists, visited);
                visited[i] = false;
            }
        }
    }

    return count;
}

int countSegments(const vector<vector<int>>& colorLists, const vector<int>& sequence) {
    int result = 0;
    vector<bool> visited(sequence.size(), false);

    for (int i = 0; i < sequence.size(); ++i) {
        result += backtrack(i, -1, colorLists, visited);
    }

    return result;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int N, M, L;
        cin >> N >> M >> L;

        vector<vector<int>> colorLists(M);
        for (int i = 0; i < M; ++i) {
            int K;
            cin >> K;
            colorLists[i].resize(K);
            for (int j = 0; j < K; ++j) {
                cin >> colorLists[i][j];
            }
        }

        vector<int> sequence(L);
        for (int i = 0; i < L; ++i) {
            cin >> sequence[i];
        }

        // Output
        cout << countSegments(colorLists, sequence) << endl;
    }

    return 0;
}
