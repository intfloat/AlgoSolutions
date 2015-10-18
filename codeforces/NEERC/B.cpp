#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> x(n), y(n);
    FOR(i, n) {
        scanf("%d %d", &x[i], &y[i]);
        if (x[i] < y[i]) swap(x[i], y[i]);
    }
    vector<int> xs = x;
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
    ll res = 0;
    int rlen, rwid;
    FOR(i, xs.size()) {
        int len = xs[i];
        vector<int> ys;
        FOR(j, n) {
            if (x[j] >= len) {
                ys.push_back(y[j]);
            }
        }
        sort(ys.begin(), ys.end(), greater<int>());
        FOR(j, ys.size()) {
            ll cur = (ll)len * (ll)ys[j] * (ll)(j + 1);
            if (cur > res) {
                res = cur; rlen = len; rwid = ys[j];
            }
        }
    }
    cout << res << endl;
    cout << rlen << " " << rwid << endl;
    return 0;
}
