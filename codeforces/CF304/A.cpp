#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    ll k, n, w;
    cin >> k >> n >> w;
    ll cost = k * w * (w + 1) / 2;
    if (cost <= n) cout << 0 << endl;
    else cout << cost - n << endl;
    return 0;
}
