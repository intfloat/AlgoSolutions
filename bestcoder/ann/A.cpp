#include <algorithm>
#include <cstdio>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
inline void solve() {
    int n, m, p, q;
    scanf("%d %d %d %d", &n, &m, &p, &q);
    if (p * m <= q) {
        printf("%d\n", n * p);
    }
    else {
        int res = (n / m) * q;
        res += min(q, p * (n % m));
        printf("%d\n", res);
    }
    return;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
