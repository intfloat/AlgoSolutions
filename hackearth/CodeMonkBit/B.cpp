#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
inline void solve() {
    ll p, m;
    scanf("%lld %lld", &p, &m);
    int res = 0;
    FOR(i, 63) {
        ll t = (1ll << i);
        if ((t & p) != (t & m)) ++res;
    }
    printf("%d\n", res);
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
