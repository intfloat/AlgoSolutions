#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void solve() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> v(M);
    FOR(i, M) cin >> v[i];
    vector<int> h(N), p(N);
    FOR(i, N) { cin >> p[i] >> h[i]; }
    double l = 0, r = 1e6;
    while (r - l > 1e-6) {
        double mid = (l + r) / 2.0;
        int cur = 0;
        bool ff = true;
        FOR(i, N) {
            bool ok = false;
            if (p[i] == 0) continue;
            FOR(d, M) {
                int h1 = h[i] - d, h2 = h[i] + d;
                if (h1 >= 0 && v[h1] * p[i] < 0 && mid >= -1.0 * (double)p[i] / v[h1]) {
                    cur += d;
                    ok = true;
                    break;
                }
                if (h2 < M && v[h2] * p[i] < 0 && mid >= -1.0 * (double)p[i] / v[h2]) {
                    cur += d;
                    ok = true;
                    break;
                }
            }
            if (!ok || cur > Q) { ff = false; break; }
        }
        if (mid > 1e5 && !ff) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        if (!ff) l = mid;
        else r = mid;
    }
    cout << ceil(l) << endl;
    return;
}
int main() {
    int TestCase;
    cin >> TestCase;
    FOR(caseID, TestCase) {
        cout << "Case #" << caseID + 1 << ": ";
        solve();
    }
    return 0;
}
