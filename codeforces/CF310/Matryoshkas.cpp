#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
typedef pair<ll, int> point;
int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int> > g(n, vector<int>());
    vector<int> cnt(k);
    int len = 0, res = 0;
    FOR(i, k) {
        cin >> cnt[i];
        g[i].resize(cnt[i]);
        FOR(j, cnt[i]) {
            cin >> g[i][j];
        }
        if (g[i][0] == 1) {
            for (int j = 1; j < g[i].size(); ++j) {
                if (g[i][j] == g[i][j - 1] + 1) {
                    ++len;
                }
                else {
                    break;
                }
            }
            res += (cnt[i] - 1 - len);
        }
        else {
            res += cnt[i] - 1;
        }
    }
    res += res + k - 1;
    cout << res << endl;
    return 0;
}
