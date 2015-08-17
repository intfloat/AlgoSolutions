#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9 + 7);
vector<int> arr, prime;
vector<ll> res;
int rep[61], n;
inline int mask(int p, int c) {
    if (c == 0) return 0;
    --c;
    if (p == 2) return (1 << c);
    if (p == 3) return (1 << (c + 5));
    if (p == 5) return (1 << (c + 8));
    if (p == 7) return (1 << (c + 10));
    FOR(i, prime.size()) {
        if (prime[i] == p) {
            return (1 << (i + 8));
        }
    }
    assert(false);
}
inline int normalize(int num) {
    for (int i = 4; i > 0; --i) {
        if (num & (1 << i)) {
            num = ((num >> i) << i);
            break;
        }
    }
    if (num & (1 << 7)) {
        num = num & (~((1 << 6) + (1 << 5)));
    }
    else if (num & (1 << 6)) {
        num = num & (~(1 << 5));
    }
    if (num & (1 << 9)) {
        num = num & (~(1 << 8));
    }
    if (num & (1 << 11)) {
        num = num & (~(1 << 10));
    }
    return num;
}
vector<vector<ll> > fac(6, vector<ll>((1 << 20) + 5, 0));
const ll INF = (ll)(1e16);
vector<ll> cc(25);
vector<int> trim(1 << 12);
vector<int> mp(17);
inline bool cmp(int pv, int cur) {
    int cm = (pv & cur);
    if (cm == cur) return true;
    cur -= cm; pv -= cm;
    ll v1 = fac[mp[pv % (1 << 5)]][pv >> 5];
    ll v2 = fac[mp[cur % (1 << 5)]][cur >> 5];
    assert(!(v1 == INF && v2 == INF));
    return v1 > v2;
}
inline void solve() {
    vector<vector<int> > dp(2, vector<int>(n));
    res.resize(n + 1);
    res[1] = *min_element(arr.begin(), arr.end());
    FOR(i, n) dp[0][i] = rep[arr[i]];
    bool idx = 1;
    int mn = -1;
    for (int i = 2; i <= n; ++i) {
        int tmp = (rep[arr[i - 1]] | dp[!idx][i - 2]);
        dp[idx][i - 1] = trim[tmp % (1 << 12)] + ((tmp >> 12) << 12);
        mn = dp[idx][i - 1];
        for (int j = i; j < n; ++j) {
            tmp = (rep[arr[j]] | dp[!idx][j - 1]);
            dp[idx][j] = trim[tmp % (1 << 12)] + ((tmp >> 12) << 12);
            if (cmp(mn, dp[idx][j])) {
                mn = dp[idx][j];
            }
        }
        ll mul = 1ll;
        FOR(j, 25) {
            if (mn & (1 << j)) {
                mul = (mul * cc[j]) % MOD;
            }
        }
        res[i] = mul;
        idx = !idx;
    }
}
inline void preprocess() {
    vector<bool> ok(61, true);
    ok[0] = ok[1] = false;
    memset(rep, 0, sizeof rep);
    for (int i = 2; i <= 60; ++i) {
        if (ok[i]) {
            prime.push_back(i);
            for (int j = i + i; j <= 60; j += i) {
                ok[j] = false;
            }
        }
    }
    for (int i = 2; i <= 60; ++i) {
        FOR(j, prime.size()) {
            int t = i, cnt = 0;
            while (t % prime[j] == 0) {
                t /= prime[j];
                ++cnt;
            }
            rep[i] += mask(prime[j], cnt);
        }
    }
    cc[0] = 2; cc[1] = 4; cc[2] = 8; cc[3] = 16; cc[4] = 32;
    cc[5] = 3; cc[6] = 9; cc[7] = 27; cc[8] = 5; cc[9] = 25;
    cc[10] = 7; cc[11] = 49;
    for (int i = 12; i < 25; ++i) {
        cc[i] = prime[i - 8];
    }
    for (int i = 0; i < 6; ++i) {
        FOR(j, 1 << 20) {
            int k = normalize((j << 5) + (1 << i) / 2);
            ll mul = 1ll;
            if (i > 0) {
                mul = fac[i - 1][j] * 2ll;
                fac[i][j] = min(mul, INF);
                continue;
            }
            FOR(p, 25) {
                if ((1 << p) & k) {
                    mul *= cc[p];
                }
                if (mul >= INF) {
                    mul = INF;
                    break;
                }
            }
            fac[i][j] = mul;
        }
    }
    FOR(i, trim.size()) {
        trim[i] = normalize(i);
    }
    mp[0] = 0, mp[1] = 1, mp[2] = 2, mp[4] = 3, mp[8] = 4, mp[16] = 5;
    solve();
}
int main() {
    int m;
    scanf("%d %d", &n, &m);
    arr.resize(n);
    FOR(i, n) {
        scanf("%d", &arr[i]);
    }
    preprocess();
    int len;
    FOR(i, m) {
        scanf("%d", &len);
        printf("%d\n", (int)res[len]);
    }
    return 0;
}
