#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll MOD = (ll)(1e9 + 7);
bool cmp(const pii& a, const pii& b) {
    if (a.second != b.second) return a.second > b.second;
    else return a.first < b.first;
}
inline void solve() {
    int N;
    cin >> N;
    vector<pii> arr(N);
    FOR(i, N) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end(), cmp);
    set<ll> up;
    up.insert(INT_MIN);
    int ptr = 0;
    ll res = 0;
    while (ptr < N) {
        int i = ptr;
        vector<ll> sm, sq, pos;
        for (i = ptr; i < N && arr[i].second == arr[ptr].second; ++i) {
            ll x = arr[i].first;
            auto it = up.upper_bound(x); --it;
            ll tlow = *it;
            int idx = upper_bound(pos.begin(), pos.end(), tlow) - pos.begin();
            if (idx < (int)pos.size()) {
                ll cnt = pos.size() - idx;
                ll tmp = (x * x) % MOD;
                res = (res + (cnt * tmp) % MOD) % MOD;
                if (idx - 1 >= 0) tmp = ((sq.back() - sq[idx - 1]) % MOD + MOD) % MOD;
                else tmp = sq.back() % MOD;
                res = (res + tmp) % MOD;

                if (idx - 1 >= 0) tmp = ((sm.back() - sm[idx - 1]) % MOD + MOD) % MOD;
                else tmp = sm.back() % MOD;
                tmp = (2ll * x * tmp) % MOD;
                tmp = (tmp + MOD) % MOD;
                res = (res - tmp) % MOD;
                res = (res + MOD) % MOD;
            }
            pos.push_back(x);
            if (!sm.empty()) {
                ll tmp = (sm.back() + x) % MOD;
                tmp = (tmp + MOD) % MOD;
                sm.push_back(tmp);
            }
            else {
                ll tmp = (x % MOD + MOD) % MOD;
                sm.push_back(tmp);
            }
            if (!sq.empty()) {
                ll tmp = sq.back() + (x * x) % MOD;
                sq.push_back(tmp % MOD);
            }
            else sq.push_back((x * x) % MOD);
        }
        for (int j = ptr; j < i; ++j) {
            up.insert(arr[j].first);
        }
        ptr = i;
    }
    cout << res << endl;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}
