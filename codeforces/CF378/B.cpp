#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> l(n), r(n);
    FOR(i, n) {
        scanf("%d %d", &l[i], &r[i]);
    }
    int lcnt = accumulate(l.begin(), l.end(), 0);
    int rcnt = accumulate(r.begin(), r.end(), 0);
    int cur = abs(lcnt - rcnt);
    int mx = -1, pos = -1;
    FOR(i, n) {
        int nl = lcnt - l[i] + r[i];
        int nr = rcnt - r[i] + l[i];
        int nval = abs(nl - nr);
        if (nval > mx) {
            mx = nval;
            pos = i + 1;
        }
    }
    if (mx <= cur) printf("0\n");
    else printf("%d\n", pos);
    return 0;
}
