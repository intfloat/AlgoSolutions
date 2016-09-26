#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
vector<vector<int> > g;
int solve(int pos) {
    int ret = 0;
    FOR(i, g[pos].size()) {
        ret = max(ret, solve(g[pos][i]));
    }
    return ret + 1;
}
int main() {
    int n, from, to;
    cin >> n;
    FOR(i, n) g.push_back(vector<int>());
    vector<bool> root(n, true);
    FOR(i, n - 1) {
        cin >> from >> to;
        root[to] = false;
        g[from].push_back(to);
    }
    FOR(i, n) {
        if (root[i]) {
            cout << solve(i) << endl;
            break;
        }
    }
    return 0;
}
