#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 100005;
typedef long long E;
int n;
inline void update(ll f[], int pos, E val) {
    if (pos == 0) return;
    while (pos <= n) {
        f[pos] += val;
        pos += pos & (-pos);
    }
}
inline E query(ll f[], int pos) {
    E ret = 0;
    while (pos > 0) {
        ret += f[pos];
        pos -= pos & (-pos);
    }
    return ret;
}
ll bit[12][MAX_N];
int mp[MAX_N], K, x;
int main() {
    memset(bit, 0, sizeof bit);
    scanf("%d %d", &n, &K);
    FOR(i, n) {
        scanf("%d", &x);
        mp[x] = i + 1;
    }
    FOR(i, n) {
        update(bit[1], mp[i + 1], 1);
        for (int l = 2; l <= K + 1; ++l) {
            ll val = query(bit[l - 1], mp[i + 1] - 1);
            update(bit[l], mp[i + 1], val);
        }
    }
    ll res = query(bit[K + 1], n);
    cout << res << endl;
    return 0;
}
