#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    ll m, n, b, mod;
    cin >> n >> m >> b >> mod;
    vector<ll> arr(n);
    FOR(i, n) cin >> arr[i];
    vector<vector<ll> > prev(m + 1, vector<ll>(b + 1, 0)), cur(m + 1, vector<ll>(b + 1, 0));    
    prev[0][0] = 1;
    for (int i = 1; i <= m; ++i) {
        if (arr[0] * i <= b) prev[i][arr[0] * i] = 1;
        else break;
    }
    for (int i = 1; i < n; ++i) {
        FOR(line, m + 1) FOR(bug, b + 1) {
            cur[line][bug] += prev[line][bug];
            if (bug >= arr[i] && line > 0) cur[line][bug] += cur[line - 1][bug - arr[i]];
            cur[line][bug] %= mod;            
        }
        prev = cur;
        FOR(i, cur.size()) FOR(j, cur[i].size()) cur[i][j] = 0;
    }
    ll res = 0;
    FOR(i, b + 1) res = (res + prev[m][i]) % mod;    
    cout << res << endl;
    return 0;
}
