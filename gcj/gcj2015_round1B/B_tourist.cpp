#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int r, c, n;
    scanf("%d %d %d", &r, &c, &n);
    if (r > c) {
      swap(r, c);
    }
    int ans = r * (c - 1) + (r - 1) * c;
    n = r * c - n;
    int real_n = n;
    if (r == 1) {
      int twos = min(n, (c - 1) / 2);
      n -= twos;
      ans -= twos * 2;
      int ones = min(n, 1 - c % 2);
      n -= ones;
      ans -= ones * 1;
    } else {
      int fours = min(n, max(((r - 2) * (c - 2) + 1) / 2, 0));
      n -= fours;
      ans -= fours * 4;
      int threes = min(n, (r - 2) / 2 + (c - 2) / 2 + (r - 2 + 1 - c % 2) / 2 + (c - 2 + 1 - r % 2) / 2);
      n -= threes;
      ans -= threes * 3;
      int twos = min(n, 2 + 2 * (r % 2) * (c % 2));
      n -= twos;
      ans -= twos * 2;
      {
        int old_ans = ans;
        ans = r * (c - 1) + (r - 1) * c;
        n = real_n;
        int fours = min(n, max(((r - 2) * (c - 2)) / 2, 0));
        n -= fours;
        ans -= fours * 4;
        int threes = min(n, (r - 1) / 2 + (c - 1) / 2 + (r - 1 - 1 + c % 2) / 2 + (c - 1 - 1 + r % 2) / 2);
        n -= threes;
        ans -= threes * 3;
        int twos = min(n, 2 - 2 * (r % 2) * (c % 2));
        n -= twos;
        ans -= twos * 2;
        ans = min(old_ans, ans);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
