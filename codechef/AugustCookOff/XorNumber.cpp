#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
int main() {
    map<ll, ll> res;
    res[1ll] = 2ll;
    for (int i = 2; i < 31; ++i) {
        ll num = (1ll << i) - 1ll;
        res[num] = (num >> 1);
    }
    int T, n;
    scanf("%d", &T);
    FOR(i, T) {
        scanf("%d", &n);
        if (res.find(n) == res.end()) {
            printf("-1\n");
        }
        else {
            printf("%d\n", (int)res[n]);
        }
    }
    return 0;
}
