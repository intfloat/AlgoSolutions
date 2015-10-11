#include <vector>
#include <stdio.h>
#include <algorithm>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
inline void solve() {
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    FOR(i, n) scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());
    ll sm = 0;
    FOR(i, arr.size()) {
        sm += arr[i];
        ll cur = (ll)i * (ll)(i + 1) / 2;
        if (sm < cur) {
            printf("The data have been tampered with!\n");
            return;
        }
    }
    if (sm != (ll)n * (n - 1) / 2) printf("The data have been tampered with!\n");
    else printf("It seems to have no problem.\n");
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
