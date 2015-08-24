#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll get(ll a, ll b, ll c, ll rem, bool f) {
    ll d = min(rem, a - b - c);
    ll ret = 0;
    if (f) ret = (rem + 1ll) * (rem + 2ll) / 2ll;
    if (d < 0) return ret;
    ret -= (d + 1ll) * (d + 2ll) / 2ll;
    return ret;
}
int main() {
    ll a, b, c, l;
    cin >> a >> b >> c >> l;
    ll res = 0;
    for (ll i = 0; i <= l; ++i) {
        res += get(a + i, b, c, l - i, true);
        res += get(b + i, a, c, l - i, false);
        res += get(c + i, a, b, l - i, false);
    }
    cout << res << endl;
    return 0;
}
