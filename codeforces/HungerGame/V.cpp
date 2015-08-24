#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll x, l, r;
    cin >> x >> l >> r;
    ll mn = (x ^ l);
    ll mx = (x ^ l);
    ++r;
    for (int i = 62; i >= 0; --i) {
        for (int j = 62; j >= 0; --j) {
            ll ii = (1ll << i);
            ll jj = (1ll << j);
            if (l & (1ll << i)) continue;
            if (!(r & (1ll << j))) continue;
            ll xl = ((x >> i) << i);
            xl = xl ^ (ii + (l & ~(ii - 1ll)));
            ll rl = ((x >> j) << j);
            rl = rl ^ ((r & ~(jj - 1ll)) - jj);
            ll tmp = (rl & xl);
            if ((i < j && tmp == rl) || (i > j && tmp == xl) || (i == j && xl == rl)) {
                ll t = max(rl, xl);
                ll d = (1ll << min(i, j)) - 1ll;
                if ((t ^ x) <= l || (t ^ x) >= r || (x ^ (t + d)) <= l || (x ^ (t + d)) >= r) continue;
                mn = min(mn, t);
                mx = max(mx, t + d);
            }
        }
    }
    cout << mn << " " << mx << endl;
    return 0;
}
