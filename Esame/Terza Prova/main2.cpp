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

    for (const auto& job : jobs) {
        cout << job.index << " ";
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
