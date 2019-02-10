#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
typedef long long ll;
typedef pair<int, int> pii;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int, int> cnt;
        FOR(i, wall.size()) {
            int acc = 0;
            FOR(j, wall[i].size()) {
                if (j != 0) ++cnt[acc];
                acc += wall[i][j];
            }
        }
        int val = 0;
        for (auto it = cnt.begin(); it != cnt.end(); ++it) {
            if (it->second > val) {
                val = it->second;
            }
        }
        return wall.size() - val;
    }
};

int main() {
    Solution solution;
    return 0;
}