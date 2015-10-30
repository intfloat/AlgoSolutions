#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
inline void solve() {
    int n;
    scanf("%d", &n);
    vector<int> arr(n), ori;
    FOR(i, n) scanf("%d", &arr[i]);
    ori = arr;
    FOR(i, n) arr[i] *= arr[i];
    ll acute = 0, right = 0, obtuse = 0;
    FOR(i, n) {
        int low = i, up = i, uu = i;
        for (int j = i + 1; j < n; ++j) {
            int cur = arr[i] + arr[j];
            int mx = ori[i] + ori[j];
            low = max(low, j + 1);
            up = max(up, j + 1);
            uu = max(uu, j + 1);
            while (low < n && arr[low] < cur) ++low;
            while (up < n && arr[up] <= cur) ++up;
            while (uu < n && mx > ori[uu]) ++uu;
            acute += (low - j - 1);
            right += (up - low);
            obtuse += (uu - up);
        }
    }
    printf("%lld %lld %lld\n", acute, right, obtuse);
}
int main() {
    solve();
    return 0;
}
