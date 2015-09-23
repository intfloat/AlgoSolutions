#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
inline void solve() {
    int n, k, t;
    scanf("%d %d", &n, &k);
    vector<int> arr(n);
    FOR(i, n) {
        scanf("%d", &t);
        arr[i] = __builtin_popcount(t);
    }
    sort(arr.begin(), arr.end(), greater<int>());
    int res = accumulate(arr.begin(), arr.begin() + k, 0);
    printf("%d\n", res);
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
