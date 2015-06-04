#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<int> diff(n);
    FOR(i, n) cin >> diff[i];
    int res = 0, total, mn, mx;
    FOR(i, 1 << n) {
        if (__builtin_popcount(i) < 2) continue;
        total = 0; mn = INT_MAX; mx = INT_MIN;
        FOR(j, n) {
            if (i & (1 << j)) {
                total += diff[j];
                mn = min(mn, diff[j]);
                mx = max(mx, diff[j]);
            }
        }
        if (total >= l && total <= r && mx - mn >= x) ++res;
    }
    cout << res << endl;
    return 0;
}
