#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
const long long inf_hung = (long long) 1e16;
long long a[2010][2010];
// min matching
long long hungarian(long long n, long long m) {
  vector <long long> u(n + 1), v(m + 1), p(m + 1), way(m + 1);
  for (long long i = 1; i <= n; i++) {
    p[0] = i;
    long long j0 = 0;
    vector <long long> minv(m + 1, inf_hung);
    vector <char> used(m + 1, false);
    do {
      used[j0] = true;
      long long i0 = p[j0], delta = inf_hung, j1;
      for (long long j = 1; j <= m; j++) {
        if (!used[j]) {
          long long cur = a[i0][j] - u[i0] - v[j];
          if (cur < minv[j]) {
            minv[j] = cur;
            way[j] = j0;
          }
          if (minv[j] < delta) {
            delta = minv[j];
            j1 = j;
          }
        }
      }
      for (long long j = 0; j <= m; j++) {
        if (used[j]) {
          u[p[j]] += delta;
          v[j] -= delta;
        } else {
          minv[j] -= delta;
        }
      }
      j0 = j1;
    } while (p[j0] != 0);
    do {
      long long j1 = way[j0];
      p[j0] = p[j1];
      j0 = j1;
    } while (j0);
  }
  return -v[0];
}
const int MAX_N = 1005;
ll cost[MAX_N][35], dp[MAX_N][31][31];
vector<vector<int> > g(MAX_N);
int N, K, P;
void calc(int idx, int p) {
    if (dp[idx][0][0] >= 0) return;
    FOR(j, K) {
        FOR(i, K) {
            // case 1
            ll best1 = P + cost[idx][i];
            FOR(ii, g[idx].size()) {
                int to = g[idx][ii];
                if (to == p) continue;
                ll mn = 1e12;
                calc(to, idx);
                FOR(jj, K) {
                    mn = min(mn, dp[to][jj][i]);
                }
                best1 += mn;
            }
            dp[idx][i][j] = best1;
            // case 2
            ll best2 = cost[idx][i];
            int cnt = (int)g[idx].size();
            if (K >= cnt) {
                FOR(ii, g[idx].size()) {
                    int to = g[idx][ii];
                    FOR(jj, K) {
                        if (p == -1) {
                            a[ii + 1][jj + 1] = dp[to][jj][i];
                        }
                        else {
                            if (jj == j && to == p) a[ii + 1][jj + 1] = 0;
                            else if (jj != j && to == p) a[ii + 1][jj + 1] = 1e12;
                            else if (jj == j && to != p) a[ii + 1][jj + 1] = 1e12;
                            else a[ii + 1][jj + 1] = dp[to][jj][i];
                        }
                    }
                }
                ll rr = hungarian(cnt, K);
                best2 += rr;
                dp[idx][i][j] = min(best1, best2);
            }
        }
    }
}
ll solve() {
    cin >> N >> K >> P;
    FOR(i, N) FOR(j, K) cin >> cost[i][j];
    FOR(i, N) g[i].clear();
    FOR(i, N - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v); g[v].push_back(u);
    }
    FOR(i, N) FOR(j, K) FOR(k, K) dp[i][j][k] = -1;
    calc(0, -1);
    ll res = inf_hung;
    FOR(i, K) {
        res = min(res, dp[0][i][0]);
    }
    return res;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        printf("Case #%d: %lld\n", i + 1, solve());
    }
    return 0;
}
