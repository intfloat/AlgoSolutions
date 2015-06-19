#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    ll n, res;
    cin >> n;
    if (n < 10) {
        cout << n << endl;
        return 0;
    }
    res = 0;
    ll cur = 10;
    int bits = 1;
    while (cur <= n) {
        res += 9ll * (cur / 10) * bits;
        cur = cur * 10ll;
        ++bits;
    }
    cur /= 10;
    res += (n - cur + 1) * bits;
    cout << res << endl;
    return 0;
}
