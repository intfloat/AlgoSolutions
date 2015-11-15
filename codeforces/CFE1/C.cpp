#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const long double pi = 4.0 * atan(1.0);
int main() {
    int n, x, y;
    scanf("%d", &n);
    vector<pii> arr(n);
    vector<pair<long double, int> > g;
    FOR(i, n) {
        scanf("%d %d", &x, &y);
        long double ang = 0;
        if (x == 0 && y > 0) ang = pi / (long double)2;
        else if (x == 0 && y < 0) ang = pi + pi / (long double)2;
        else if (x > 0) {
            ang = atan(1.0 * (long double)y / x);
            if (ang < 0) ang += 2 * pi;
        }
        else {
            x = -x;
            ang = pi - atan(1.0 * (long double)y / x);
        }
        g.push_back(make_pair(ang, i + 1));
    }
    sort(g.begin(), g.end());
    g.push_back(g[0]);
    g.back().first += 2 * pi;
    long double mn = 10 * pi;
    pii res;
    for (int i = 1; i < (int)g.size(); ++i) {
        if (g[i].first - g[i - 1].first < mn) {
            mn = g[i].first - g[i - 1].first;
            res = make_pair(g[i].second, g[i - 1].second);
        }
    }
    printf("%d %d\n", res.first, res.second);
    return 0;
}
