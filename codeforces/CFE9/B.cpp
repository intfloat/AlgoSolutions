#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char s[500005];
vector<int> p;
int n;
ll solve(ll cur) {
    ll ret = cur;
    FOR(i, n) {
        if (s[i] == 'A') {
            cur += p[i];
            ret = max(ret, cur);
        }
        else {
            cur -= p[i];
        }
    }
    return ret;
}
int main() {
    scanf("%d", &n);
    p.resize(n);
    FOR(i, n) scanf("%d", &p[i]);
    scanf("%s", s);
    ll res = 0;
    FOR(i, n) {
        if (s[i] == 'B') {
            res += p[i];
        }
    }
    ll cc = res;
    res = max(res, solve(cc));
    reverse(s, s + n);
    reverse(p.begin(), p.end());
    res = max(res, solve(cc));
    cout << res << endl;
    return 0;
}
