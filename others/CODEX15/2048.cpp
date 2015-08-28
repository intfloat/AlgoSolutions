#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9 + 7);
int main() {
    int T;
    scanf("%d", &T);
    vector<int> arr(T);
    FOR(i, T) scanf("%d", &arr[i]);
    int mx = *max_element(arr.begin(), arr.end());
    vector<ll> pw(20);
    pw[0] = 1ll;
    for (int i = 1; i < 20; ++i) pw[i] = pw[i - 1] * 2ll;
    vector<ll> res(mx + 1, 0ll);
    res[0] = 1;
    for (int i = 0; i < 20; ++i) {
        for (int j = pw[i]; j <= mx; ++j) {
            res[j] = (res[j] + res[j - pw[i]]) % MOD;
        }
    }
    FOR(i, T) {
        printf("%lld\n", res[arr[i]]);
    }
    return 0;
}
