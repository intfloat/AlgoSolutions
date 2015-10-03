#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAX_N = 100005;
int arr[MAX_N];
typedef int E;
typedef long long ll;
E pre[MAX_N], suf[MAX_N];
int n, m;
inline void update(E* f, int pos, E val) {
    if (pos == 0) return;
    while (pos <= n) {
        f[pos] += val;
        pos += pos & (-pos);
    }
}
inline E query(E* f, int pos) {
    E ret = 0;
    while (pos > 0) {
        ret += f[pos];
        pos -= pos & (-pos);
    }
    return ret;
}
inline void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    memset(pre, 0, sizeof pre);
    memset(suf, 0, sizeof suf);
    ll res = 0;
    for (int i = n - 1; i >= m; --i) {
        res += query(suf, arr[i] - 1);
        update(suf, arr[i], 1);
    }
    ll cur = res;
    for (int i = m; i < n; ++i) {
        update(suf, arr[i], -1);
        cur -= query(pre, n) - query(pre, arr[i]) + query(suf, arr[i] - 1);
        cur += query(pre, n) - query(pre, arr[i - m]) + query(suf, arr[i - m] - 1);
        update(pre, arr[i - m], 1);
        res = min(res, cur);
    }
    printf("%lld\n", res);
}
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}
