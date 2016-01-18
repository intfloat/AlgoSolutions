#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
#define double long double
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll N, A, B, tot;
vector<ll> t;
ll work(ll up) {
    ll res = 0, period = 0;
    if (up >= tot) {
        FOR(i, t.size()) {
            period += t[i] * t[i];
        }
        res = period * (up / tot);
        up %= tot;
    }
    ll cur = 0;
    FOR(i, t.size()) {
        if (cur + t[i] < up) {
            cur += t[i];
            res += t[i] * t[i];
        }
        else {
            res += (up - cur) * (up - cur);
            break;
        }
    }
    return res;
}
inline void solve() {
    scanf("%I64d %I64d %I64d", &N, &A, &B);
    t.resize(N);
    FOR(i, N) scanf("%I64d", &t[i]);
    tot = accumulate(t.begin(), t.end(), 0ll);
    ll area = work(B) - work(A);
    double res = 0.5 * (double)area / (double)(B - A);
    cout << fixed << setprecision(10) << res << endl;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}
