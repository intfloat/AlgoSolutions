#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef priority_queue<pii, vector<pii>, greater<pii> > mn_queue;
inline void solve() {
    ll L, N, M, D, cost;
    scanf("%I64d %I64d %I64d %I64d", &L, &N, &M, &D);
    mn_queue washer;
    FOR(i, N) {
        scanf("%I64d", &cost);
        // earliest finish time, duration
        washer.push({cost, cost});
    }
    vector<ll> t1;
    FOR(i, L) {
        pii tp = washer.top(); washer.pop();
        t1.push_back(tp.first);
        washer.push({tp.first + tp.second, tp.second});
    }

    priority_queue<ll, vector<ll>, greater<ll> > dryer;
    FOR(i, min(M, L)) dryer.push(0);
    ll res = 0;
    FOR(i, t1.size()) {
        ll tp = dryer.top(); dryer.pop();
        if (tp > t1[i]) {
            dryer.push(tp + D);
            res = max(res, tp + D);
        }
        else {
            dryer.push(t1[i] + D);
            res = max(res, t1[i] + D);
        }
    }
    printf("%I64d\n", res);
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
