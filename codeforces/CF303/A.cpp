#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    int n;
    cin >> n;
    vector<vector<int> > g(n, vector<int>(n));
    FOR(i, n) FOR(j, n) cin >> g[i][j];
    vector<bool> ok(n, true);
    FOR(i, n) FOR(j, n) {
        if (i == j) continue;
        if (g[i][j] == 1) ok[i] = false;
        if (g[i][j] == 2) ok[j] = false;
        if (g[i][j] == 3) ok[i] = ok[j] = false;
    }
    cout << accumulate(ok.begin(), ok.end(), 0) << endl;
    FOR(i, ok.size()) {
        if (ok[i]) cout << i + 1 << " ";
    }
    cout << endl;
    return 0;
}
