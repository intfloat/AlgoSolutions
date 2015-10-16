#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = (ll)(1e9 + 7);
int main() {
    int n, val = 0;
    scanf("%d", &n);
    vector<int> arr(n);
    FOR(i, n) scanf("%d", &arr[i]);
    FOR(i, n) val ^= arr[i];
    if (val != 0) {
        printf("0\n");
        return 0;
    }
    ll res = 1;
    FOR(i, n - 1) res = (res * 2ll) % MOD;
    res = (res - 1 + MOD) % MOD;
    printf("%lld\n", res);
    return 0;
}
