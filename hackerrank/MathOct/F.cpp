#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = 1234567891;
const int MAX_N = 100005;
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> arr(n), coeff(m + 1);
    map<int, int> mp;
    FOR(i, n) {
        scanf("%d", &arr[i]);
        ++mp[arr[i]];
    }
    FOR(i, m + 1) scanf("%d", &coeff[i]);
    vector<ll> cnt(MAX_N, 0);
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        int num = it->first, cc = it->second, i = 1;
        while (i * i < num) {
            if (num % i == 0) {
                cnt[i] += cc;
                cnt[num / i] += cc;
            }
            ++i;
        }
        if (i * i == num) cnt[num / i] += cc;
    }
    for (int i = MAX_N - 1; i >= 1; --i) {
        cnt[i] = cnt[i] * (cnt[i] - 1) / 2;
        for (int j = i + i; j < MAX_N; j += i) {
            cnt[i] = (cnt[i] - cnt[j]) % MOD;
            cnt[i] = (cnt[i] + MOD) % MOD;
        }
    }
    ll res = 0;
    for (int i = MAX_N - 1; i >= 1; --i) {
        if (cnt[i] == 0) continue;
        ll cur = 0, rr = 1;
        FOR(j, m + 1) {
            cur = (cur + rr * coeff[j]) % MOD;
            rr = (rr * i) % MOD;
        }
        res = (res + cur * cnt[i]) % MOD;
        res = (res + MOD) % MOD;
    }
    printf("%lld\n", res);
    return 0;
}
