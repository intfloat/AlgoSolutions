#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int cnt;
    void solve(int step, vector<bool>& chosen) {
        if (step <= 1) {
            ++this->cnt;
            return;
        }
        for (int i = 1; i < chosen.size(); ++i) {
            if (!chosen[i] && (i % step == 0 || step % i == 0)) {
                chosen[i] = true;
                solve(step - 1, chosen);
                chosen[i] = false;
            }
        }
    }
public:
    int countArrangement(int N) {
        this->cnt = 0;
        vector<bool> chosen(N + 1, false);
        solve(N, chosen);
        return this->cnt;
    }
};

int main() {
    Solution sol;
    for (int i = 2; i <= 15; ++i) {
        cout << sol.countArrangement(i) << endl;
    }
    return 0;
}