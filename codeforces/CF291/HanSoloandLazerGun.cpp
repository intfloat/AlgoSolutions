#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

int main() {
    int n, x0, y0, x, y;
    cin >> n >> x0 >> y0;
    set<pair<int, int> > res;
    FOR(i, n) {
        cin >> x >> y;
        x -= x0; y-= y0;
        int ax = abs(x), ay = abs(y);
        int g = __gcd(ax, ay);
        x /= g; y /= g;
        if (x < 0) { x = -x; y = -y; }
        else if (x == 0) y = abs(y);
        res.insert(make_pair(x, y));
    }
    cout << res.size() << endl;
    return 0;
}
