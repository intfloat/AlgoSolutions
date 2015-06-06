#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef pair<int, int> point;
vector<point> hor, ver;
void solve() {
    int n;
    point x, y;
    scanf("%d", &n);
    hor.clear(); ver.clear();
    FOR(i, n) {
        scanf("%d %d %d %d", &x.first, &x.second, &y.first, &y.second);
        if (x > y) swap(x, y);
        if (x.first == y.first) { ver.push_back(x); ver.push_back(y); }
        else {
            hor.push_back(x);
            hor.push_back(y);
        }
    }
    // sort(hor.begin(), hor.end());
    int res = 0;
    int x1, x2, y1, y2, x1y1, x1y2, x2y1, x2y2, y1x1, y1x2, y2x1, y2x2;
    FOR(v1, ver.size() / 2) for (int v2 = v1 + 1; v2 < ver.size() / 2; ++v2) {
        FOR(h1, hor.size() / 2) for (int h2 = h1 + 1; h2 < hor.size() / 2; ++h2) {
            x1 = ver[v1 * 2].first; x2 = ver[v2 * 2].first;
            x1y1 = ver[v1 * 2].second; x1y2 = ver[v1 * 2 + 1].second;
            x2y1 = ver[v2 * 2].second; x2y2 = ver[v2 * 2 + 1].second;
            y1 = hor[h1 * 2].second; y2 = hor[h2 * 2].second;
            y1x1 = hor[h1 * 2].first; y1x2 = hor[h1 * 2 + 1].first;
            y2x1 = hor[h2 * 2].first; y2x2 = hor[h2 * 2 + 1].first;
            if (min(y1, y2) > max(x1y1, x2y1) && max(y1, y2) < min(x1y2, x2y2) && min(x1, x2) > max(y1x1, y2x1) && max(x1, x2) < min(y1x2, y2x2)) {
                ++res;
            }
        }
    }
    printf("%d\n", res);
    return;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(tt, T) {
        printf("Case #%d:\n", tt + 1);
        solve();
    }
    return 0;
}
