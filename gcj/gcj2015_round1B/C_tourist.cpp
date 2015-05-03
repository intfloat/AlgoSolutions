#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

long long x[N], t[N], z[N];
pair <long long, int> p[N];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int cnt;
    scanf("%d", &cnt);
    vector < pair <int, int> > a;
    while (cnt--) {
      int d, h, m;
      scanf("%d %d %d", &d, &h, &m);
      for (int i = 0; i < h; i++) {
        a.push_back(make_pair(d, m));
        m++;
      }
    }
    sort(a.begin(), a.end());
    int n = a.size();
    for (int i = 0; i < n; i++) {
      x[i] = a[i].first;
      t[i] = a[i].second;
      z[i] = (360 - x[i]) * t[i];
    }
    int ans = n;
    set < pair <long long, int> > b;
    for (int j = 0; j < n; j++) {
      b.insert(make_pair(z[j], j));
    }
    int cur = n;
    for (int it = 0; it < 3 * n; it++) {
      int j = (*(b.begin())).second;
      if (z[j] == (360 - x[j]) * t[j]) {
        cur--;
      } else {
        cur++;
      }
      b.erase(b.begin());
      if (z[j] < (*(b.begin())).first) {
        ans = min(ans, cur);
      }
      z[j] += 360 * t[j];
      b.insert(make_pair(z[j], j));
    }
    printf("%d\n", ans);
    cerr << "test " << qq << " done" << endl;
  }
  return 0;
}
