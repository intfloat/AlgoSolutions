#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
inline void solve() {
    ll N;
    scanf("%lld", &N);
    ll cycle = N / 4;
    ll x = 0, y = 0;
    x -= 2ll * cycle;
    y -= 2ll * cycle;
    for (ll i = cycle * 4 + 1; i <= N; ++i) {
        if (i % 4 == 1) x += i;
        else if (i % 4 == 2) y += i;
        else if (i % 4 == 3) x -= i;
        else if (i % 4 == 0) y -= i;
    }
    printf("%lld %lld\n", x, y);
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
