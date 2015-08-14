#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
int main() {
    int n, m;
    cin >> n >> m;
    int mx = 0, res = m;
    vector<int> cand = {m - 1, m + 1};
    FOR(i, 2) {
        if (cand[i] < 1 || cand[i] > n) {
            continue;
        }
        int cur;
        if (cand[i] < m) cur = cand[i];
        else cur = n - cand[i] + 1;
        if (cur > mx || (cur == mx && cand[i] < res)) {
            mx = cur;
            res = cand[i];
        }
    }
    cout << res << endl;
    return 0;
}
