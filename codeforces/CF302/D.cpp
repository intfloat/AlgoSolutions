#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
const ll MOD = static_cast<ll>(1e9 + 7);

int main() {
    int n, to, u;
    scanf("%d", &n);
    vector<int> parent(n);
    vector<ll> cnt(n, 1);
    vector<vector<ll> > left(n, vector<ll>()), right(n, vector<ll>());
    vector<vector<int> > g(n, vector<int>());
    parent[0] = -1;
    FOR(i, n - 1) {
        scanf("%d", &parent[i + 1]);
        --parent[i + 1];
        g[parent[i + 1]].push_back(i + 1);
    }
    vector<int> arr;
    queue<int> q; q.push(0);
    while (!q.empty()) {
        int tp = q.front(); q.pop();
        arr.push_back(tp);
        FOR(i, g[tp].size()) {
            to = g[tp][i];
            q.push(to);
        }
    }
    reverse(arr.begin(), arr.end());
    FOR(i, arr.size()) {
        u = arr[i];
        FOR(j, g[u].size()) cnt[u] = (cnt[u] * (1 + cnt[g[u][j]])) % MOD;
        if (g[u].size() == 0) continue;
        ll tmp = 1ll;
        FOR(j, g[u].size()) {
            tmp = (tmp * (1 + cnt[g[u][j]])) % MOD;
            left[u].push_back(tmp);
        }
        tmp = 1ll;
        for (int j = g[u].size() - 1; j >= 0; --j) {
            tmp = (tmp * (1 + cnt[g[u][j]])) % MOD;
            right[u].push_back(tmp);
        }
        reverse(right[u].begin(), right[u].end());
    }    
    vector<ll> pcnt(n, 1);
    reverse(arr.begin(), arr.end());    
    FOR(i, arr.size()) {
        u = arr[i];
        FOR(j, g[u].size()) {
            to = g[u][j];
            if (j > 0) pcnt[to] = (pcnt[to] * left[u][j - 1]) % MOD;
            if (j < g[u].size() - 1) pcnt[to] = (pcnt[to] * right[u][j + 1]) % MOD;
            if (u != 0) pcnt[to] = (pcnt[to] * (1 + pcnt[u])) % MOD;
        }
    }
    vector<ll> res(n, -1);
    res[0] = cnt[0] % MOD;
    for (int i = 1; i < arr.size(); ++i) {
        u = arr[i];
        res[u] = (cnt[u] * (1 + pcnt[u])) % MOD;
    }
    FOR(i, res.size()) cout << res[i] << " ";
    cout << endl;
    return 0;
}
