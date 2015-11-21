#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int main() {
    ll x;
    cin >> x;
    x = x * 6ll;
    vector<pii> res;
    for (ll n = 1; n < 2000000; ++n) {
        ll val = n * (n + 1);
        if (x % val == 0) {
            val = x / val + n - 1;
            if (val % 3 == 0) {
                val /= 3;
                if (n < val) {
                    res.push_back({n, val});
                    res.push_back({val, n});
                }
                if (n == val) res.push_back({val, n});
            }
        }
    }
    sort(res.begin(), res.end());
    printf("%d\n", (int)res.size());
    FOR(i, res.size()) {
        printf("%I64d %I64d\n", res[i].first, res[i].second);
    }
    return 0;
}
