#include <stdio.h>
using namespace std;
const int MAX_N = 200005;
int p[MAX_N];
inline int _find(int idx) {
    if (idx != p[idx]) {
        p[idx] = _find(p[idx]);
    }
    return p[idx];
}
bool odd, even;
inline void _union(int x, int y) {
    int rx = _find(x);
    int ry = _find(y);
    if (rx == ry && x % 2 == 0) {
        even = true;
        return;
    }
    p[rx] = ry;
}
int n, m, x, y, rx, ry;
void solve() {
    scanf("%d %d", &n, &m);
    odd = false, even = false;
    for (int i = 0; i < 2 * n + 5; ++i) p[i] = i;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &x, &y);
        _union(2 * x, 2 * y + 1);
        _union(2 * x + 1, 2 * y);
    }
    for (int i = 1; i <= n; ++i) {
        if (_find(2 * i) == _find(2 * i + 1)) {
            odd = true;
            break;
        }
    }
    if (odd) printf("YES\n");
    else printf("NO\n");
    if (even) printf("YES\n");
    else printf("NO\n");
    return;
}
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}
