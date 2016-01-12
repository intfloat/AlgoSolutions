#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
inline void solve() {
    int N, P;
    scanf("%d %d", &N, &P);
    vector<ll> B(N + 1, 0);
    FOR(i, N) {
        scanf("%lld", &B[i + 1]);
    }
    ll res = 0;
    for (int i = 1; i <= N; ++i) {
        B[i] += B[i - 1];
        if (B[i] <= P) {
            res += i;
            continue;
        }
        int l = 1, r = i;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            ll val = B[i] - B[mid - 1];
            if (val > P) l = mid;
            else r = mid - 1;
        }
        if (l + 1 == r && B[i] - B[r - 1] > P) {
            l = r;
        }
        res += i - l;
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
