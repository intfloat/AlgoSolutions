// code from tourist
#include <bits/stdc++.h>
using namespace std;
const long long inf_hung = (long long) 1e16;
const long long N = 2010;
// ATTENTION: index start from 1, not 0
long long a[N][N];
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
int main() {
    return 0;
}
