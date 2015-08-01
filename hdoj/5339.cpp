#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
inline void solve() {
    int n, a;
    scanf("%d %d", &n, &a);
    vector<int> arr(n);
    FOR(i, n) {
        scanf("%d", &arr[i]);
    }
    sort(arr.begin(), arr.end(), greater<int>());
    int res = n + 1;
    for (int i = 1; i < (1 << n); ++i) {
        int cnt = 0;
        int t = a;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                t = t % arr[j];
                ++cnt;
                if (t == 0) {
                    res = min(res, cnt);
                    break;
                }
            }
        }
    }
    if (res > n) {
        printf("-1\n");
    }
    else {
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
