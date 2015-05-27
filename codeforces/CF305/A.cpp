#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const int MAX_N = 1000005;
int ok[MAX_N];
int main() {
    ll m, h1, a1, h2, a2, x1, x2, y1, y2;
    cin >> m >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;
    FOR(i, m) ok[i] = -1;
    ok[h1] = 0;
    int cnt = 1;
    ll c1, c2, b1, b2;
    while (true) {
        h1 = (x1 * h1 + y1) % m;
        if (ok[h1] != -1) { b1 = ok[h1]; c1 = cnt - ok[h1]; break; }
        ok[h1] = cnt++;
    }
    ll p1 = ok[a1];
    if (ok[a1] == -1) {
        cout << -1 << endl;
        return 0;
    }
    FOR(i, m) ok[i] = -1;
    ok[h2] = 0;
    cnt = 1;
    while (true) {
        h2 = (x2 * h2 + y2) % m;
        if (ok[h2] != -1) { b2 = ok[h2]; c2 = cnt - ok[h2]; break; }
        ok[h2] = cnt++;
    }
    ll p2 = ok[a2];
    if (ok[a2] == -1) { cout << -1 << endl; return 0; }
    if (p1 == p2) {
        cout << p1 << endl;
        return 0;
    }
    if (p1 < b1 && p2 < b2) {
        if (p1 == p2) { cout << p1 << endl; return 0; }
        else { cout << -1 << endl; return 0; }
    }
    else if (p1 < b1) {
        if (p1 >= p2 && ((p1 - p2) % c2) == 0) cout << p1 << endl;
        else cout << -1 << endl;
        return 0;
    }
    else if (p2 < b2) {
        if (p2 >= p1 && ((p2 - p1) % c1) == 0) cout << p2 << endl;
        else cout << -1 << endl;
        return 0;
    }
    if (c1 < c2) {
        swap(p1, p2); swap(c1, c2);
    }
    ll p = abs(p2 - p1);
    ll g = __gcd(c1, c2);
    ll res;
    if (p % g) { cout << -1 << endl; return 0; }
    for (ll i = 0; ; ++i) {
        ll t = p1 + c1 * i - p2;
        if (t >= 0 && t % c2 == 0) {
            res = p1 + c1 * i; break;
        }        
    }
    cout << res << endl;
    return 0;
}
