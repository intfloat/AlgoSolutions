#include <stdio.h>
#include <vector>
#include <algorithm>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
inline void solve() {
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    FOR(i, n) scanf("%d", &arr[i]);
    int pos = find(arr.begin(), arr.end(), n) - arr.begin();
    int cur = n, cnt = 1;
    for (int i = pos - 1; i >= 0; --i) {
        if (arr[i] + 1 == cur) {
            --cur;
            ++cnt;
        }
    }
    printf("%d\n", n - cnt);
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
