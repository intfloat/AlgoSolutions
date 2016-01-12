#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
inline int dis(pii& a, pii& b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
inline void solve() {
    int N, x, y;
    scanf("%d", &N);
    vector<pii> arr;
    FOR(i, N) {
        scanf("%d %d", &x, &y);
        arr.push_back({x, y});
    }
    ll res = 0;
    FOR(i, N) {
        map<int, int> cnt;
        FOR(j, N) {
            if (i == j) continue;
            ++cnt[dis(arr[i], arr[j])];
        }
        for (auto it = cnt.begin(); it != cnt.end(); ++it) {
            res += (it->second) * (it->second - 1) / 2;
        }
    }
    printf("%lld\n", res);
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
