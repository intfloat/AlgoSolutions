#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
int main() {
    int n, k, x;
    ll val = 1;
    scanf("%d %d %d", &n, &k, &x);
    FOR(i, k) val *= x;
    vector<ll> arr(n);
    FOR(i, n) scanf("%lld", &arr[i]);
    vector<ll> l(n), r(n);
    l[0] = arr[0];
    for (int i = 1; i < n; ++i) l[i] = (l[i - 1] | arr[i]);
    r[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; --i) r[i] = (r[i + 1] | arr[i]);
    ll res = 0;
    FOR(i, n) {
        ll cur = arr[i] * val;
        if (i + 1 < n) cur = (cur | r[i + 1]);
        if (i - 1 >= 0) cur = (cur | l[i - 1]);
        res = max(res, cur);
    }
    cout << res << endl;
    return 0;
}
