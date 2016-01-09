#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll n;
inline bool ok(ll mid) {
    if (mid > 1e9 + 5) return false;
    return 3ll * mid * (mid + 1) < n;
}
const ll dir_x[] = {-1, -2, -1, 1, 2, 1};
const ll dir_y[] = {2, 0, -2, -2, 0, 2};
int main() {
    cin >> n; ++n;
    ll l = 0, r = n;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        if (ok(mid)) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }
    if (l + 1 == r && ok(r)) {
        l = r;
    }
    ll rem = n - 3ll * l * (l + 1);
    ll x = (l + 1) * 2, y = 0;
    if (rem == 1) {
        cout << x - 2 << " " << y << endl;
        return 0;
    }
    FOR(i, 6) {
        if (rem <= l + 1) {
            x += dir_x[i] * (rem - 1);
            y += dir_y[i] * (rem - 1);
            cout << x << " " << y << endl;
            return 0;
        }
        else {
            x += dir_x[i] * (l + 1);
            y += dir_y[i] * (l + 1);
            rem -= (l + 1);
        }
    }
    assert(false);
    return 0;
}
