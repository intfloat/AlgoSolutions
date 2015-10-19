#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s; int n, k[100000], z; ll p[63], cnt[100][26], suff[63][102][26];
ll solve(ll x, char c) {
    if (x < 0) return 0;
    if (x < z) return cnt[x][c-'a'];
    int i = lower_bound(p, p+63, (x+1)/z+1)-p-1; ll p = 1LL<<i;
    ll v, *res=&v;
    if (2*p*z-x <= 101) {
      res = &suff[i+1][2*p*z-x][c-'a'];
      if (*res != -1) return *res;
    }
    *res = p*cnt[z-1][c-'a'];
    if (x+1 == p*z) return *res;
    ll l = p*z-k[i]%(p*z), r = (x-k[i]%(p*z))%(p*z);
    if (r >= l) *res += solve(r, c) - solve(l-1, c);
    else *res += p*cnt[z-1][c-'a'] - (solve(l-1, c) - solve(r, c));
    return *res;
}
int main() {
    p[0] = 1; for (int i=1; i < 63; i++) p[i] = p[i-1]*2;
    char t[101]; scanf("%s", t); s=t; z = s.size();
    memset(cnt, 0, sizeof cnt);
    for (int i=0; i < z; i++) for (int j=i; j < z; j++) cnt[j][s[i]-'a']++;
    memset(suff, -1, sizeof suff);
    int m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &k[i]);
    for (int i = 0; i < m; i++) {
      ll l, r; char c; scanf("%lld%lld %c", &l, &r, &c); l--; r--;
      printf("%lld\n", solve(r, c)-solve(l-1, c));
    }
    return 0;
}
