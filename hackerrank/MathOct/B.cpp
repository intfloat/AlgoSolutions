#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
ll cross(pii a, pii b, pii c) {
    ll x1 = a.first - c.first, x2 = b.first - c.first;
    ll y1 = a.second - c.second, y2 = b.second - c.second;
    return x1 * y2 - x2 * y1;
}
inline void solve() {
    pii arr[4];
    FOR(i, 3) cin >> arr[i].first >> arr[i].second;
    arr[3] = arr[0];
    ll area = abs(cross(arr[0], arr[1], arr[2])) / 2;
    ll bound = 0;
    FOR(i, 3) {
        ll dx = abs(arr[i + 1].first - arr[i].first);
        ll dy = abs(arr[i + 1].second - arr[i].second);
        ll g = __gcd(dx, dy);
        bound += g;
    }
    ll res = area + 1 - bound / 2;
    cout << res << endl;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
