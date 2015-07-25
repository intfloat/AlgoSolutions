#include <vector>
#include <algorithm>
#include <cstdio>
#include <limits.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
vector<int> number;
const ll MX = ll(1e9);
inline void preprocess() {
    for (ll i = 1; i < 100000; ++i) {
        ll t = 3ll * i * (i - 1ll) + 1ll;
        if (t <= MX) {
            number.push_back((int)t);
        }
        else {
            number.push_back(INT_MAX);
            return;
        }
    }
}
inline void solve() {
    int m;
    scanf("%d", &m);
    if (*lower_bound(number.begin(), number.end(), m) == m) {
        printf("1\n");
        return;
    }
    int up = upper_bound(number.begin(), number.end(), m) - number.begin();
    for (int i = 0; 2 * number[i] <= m; ++i) {
        if ((m - 2) % 6 != 0) break;
        int pos = lower_bound(number.begin() + i, number.begin() + up, m - number[i]) - number.begin();
        if (number[pos] == m - number[i]) {
            printf("2\n");
            return;
        }
    }
    for (int i = 3; ; ++i) {
        if ((m - i) % 6 == 0) {
            printf("%d\n", i);
            return;
        }
    }
}
int main() {
    preprocess();
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
