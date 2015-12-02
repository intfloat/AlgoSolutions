#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = (ll)(1e9 + 7);
ll p, k;
inline ll fast_pw(ll num) {
    if (num == 0) return 1ll;
    if (num == 1) return k % p;
    ll ret = fast_pw(num / 2);
    ret = (ret * ret) % p;
    if (num % 2) ret = (ret * k) % p;
    return ret;
}
int main() {
    cin >> p >> k;
    if (k == 0) {
        ll res = 1;
        FOR(i, p - 1) res = (res * p) % MOD;
        cout << res << endl;
        return 0;
    }
    vector<int> visited(p, false);
    ll res = 1;
    FOR(i, p) {
        if (visited[i]) continue;
        int ptr = i;
        ll cnt = 0;
        while (!visited[ptr]) {
            visited[ptr] = true;
            ++cnt;
            ptr = ((ll)ptr * (ll)k) % p;
        }
        ll val = fast_pw(cnt);
        if (val == 1) res = (res * p) % MOD;
    }
    cout << res << endl;
    return 0;
}
