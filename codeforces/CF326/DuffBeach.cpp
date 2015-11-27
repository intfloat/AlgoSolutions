#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = (ll)(1e9 + 7);
vector<int> tmp;
int main() {
    int n, k;
    ll l;
    cin >> n >> l >> k;
    vector<int> arr(n);
    FOR(i, n) scanf("%d", &arr[i]);
    tmp = arr;
    sort(tmp.begin(), tmp.end());
    ll num = (l + n - 1) / n;
    k = (int)min((ll)k, num);
    vector<vector<int> > f(k + 1, vector<int>(n, 0));
    vector<vector<int> > prefix(k + 1, vector<int>(n, 0));
    FOR(i, n) {
        f[1][i] = 1;
        prefix[1][i] = i + 1;
    }
    vector<int> aux(n);
    FOR(i, n) {
        aux[i] = upper_bound(tmp.begin(), tmp.end(), arr[i]) - tmp.begin();
    }
    for (int i = 2; i <= k; ++i) {
        for (int j = 0; j < n; ++j) {
            int len = aux[j];
            f[i][j] = prefix[i - 1][len - 1];
            prefix[i][len - 1] += f[i][j];
            prefix[i][len - 1] %= MOD;
        }
        for (int j = 1; j < n; ++j) {
            prefix[i][j] = (prefix[i][j] + prefix[i][j - 1]) % MOD;
        }
    }
    int rem = l % n;
    ll res = 0;
    for (int i = 0; i < rem; ++i) {
        for (int len = 1; len <= k; ++len) {
            res += ((ll)f[len][i] * ((num - len + 1) % MOD)) % MOD;
            res %= MOD;
        }
    }
    if (rem == 0) ++num;
    for (int i = rem; i < n; ++i) {
        for (int len = 1; len <= k; ++len) {
            res += ((ll)f[len][i] * ((num - 1 - len + 1) % MOD)) % MOD;
            res %= MOD;
        }
    }
    cout << res << endl;
    return 0;
}
