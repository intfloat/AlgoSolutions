#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = (ll)(1e9 + 7);
ll fast_power(ll num, int p) {
  ll ret = 1, val = num;
  while (p > 0) {
    if (p & 1) ret = (ret * val) % MOD;
    val = (val * val) % MOD;
    p >>= 1;
  }
  return ret;
}

vector<int> to;
ll calc(int init, int tot, vector<int>& pos) {
    int ptr = init, cnt = 0;
    while (pos[ptr] < 0) {
        pos[ptr] = cnt++;
        ptr = to[ptr];
    }
    int rem = cnt - pos[ptr];
    // printf("cycle length: %d\n", rem);
    ll res = fast_power(2ll, tot);
    res = (res - fast_power(2ll, tot - rem + 1)) % MOD;
    res = (res + MOD) % MOD;
    return res;
}

int main() {
    int n;
    cin >> n;
    to.resize(n + 1);
    vector<vector<int> > g(n + 1, vector<int>());
    for (int i = 1; i <= n; ++i) {
        cin >> to[i];
        g[i].push_back(to[i]);
        g[to[i]].push_back(i);
    }
    vector<int> pos(n + 1, -1);
    vector<bool> visited(n + 1, false);
    ll res = 1;
    for (int i = 1; i <= n; ++i) {
        if (visited[i]) continue;
        queue<int> q;
        q.push(i); visited[i] = true;
        int cnt = 0;
        while (!q.empty()) {
            int tp = q.front(); q.pop(); ++cnt;
            FOR(j, g[tp].size()) {
                int u = g[tp][j];
                if (!visited[u]) {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
        res = res * calc(i, cnt, pos);
        res %= MOD;
    }
    cout << res << endl;
    return 0;
}
