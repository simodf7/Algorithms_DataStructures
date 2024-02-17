#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int time;
    int penalty;
    int index;
};

bool compareJobs(const Job& a, const Job& b) {
    return a.penalty * b.time < b.penalty * a.time;
}

void minPenaltySequence(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compareJobs);

    int n = jobs.size();
    
    // dp[i][j] rappresenta la minima perdita.
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (jobs[i - 1].time <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - jobs[i - 1].time] + jobs[i - 1].penalty);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int tempo_rimanente = n;
    for (int i = n; i > 0 && tempo_rimanente > 0; --i) {
        if (dp[i][tempo_rimanente] != dp[i - 1][tempo_rimanente]) {
            cout << jobs[i - 1].index << " ";
            tempo_rimanente -= jobs[i - 1].time;
        }
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<Job> jobs(N);
        for (int i = 0; i < N; ++i) {
            cin >> jobs[i].time >> jobs[i].penalty;
            jobs[i].index = i + 1;
        }

        minPenaltySequence(jobs);
    }

    return 0;
}
