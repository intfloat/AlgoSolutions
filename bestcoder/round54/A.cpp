#include <vector>
#include <algorithm>
#include <stdio.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
vector<ll> prime;
inline void preprocess() {
    vector<bool> ok(100000, true);
    ok[0] = ok[1] = false;
    for (ll i = 2; i < ok.size(); ++i) {
        if (ok[i]) {
            prime.push_back(i);
            for (ll j = i * i; j < ok.size(); j += i) {
                ok[j] = false;
            }
        }
    }
}
inline void solve() {
    int N;
    scanf("%d", &N);
    vector<ll> arr(N);
    FOR(i, N) {
        scanf("%lld", &arr[i]);
    }
    vector<ll> factors(1, 1ll);
    FOR(i, prime.size()) {
        FOR(j, arr.size()) {
            while (arr[j] % prime[i] == 0) {
                arr[j] /= prime[i];
                if (factors.size() < 3) factors.push_back(prime[i]);
                else break;
            }
        }
        if (factors.size() >= 3) break;
    }
    if (factors.size() < 3) {
        sort(arr.begin(), arr.end());
        FOR(i, arr.size()) {
            if (arr[i] != 1 && factors.size() < 3) {
                factors.push_back(arr[i]);
            }
        }
    }
    if (factors.size() < 3) {
        printf("-1\n");
        return;
    }
    ll res = factors[1] * factors[2];
    printf("%lld\n", res);
}
int main() {
    int T;
    preprocess();
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
