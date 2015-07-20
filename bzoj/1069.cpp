#include <vector>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef pair<int, int> point;
vector<point> hull;
point mn;
inline int cross(point a, point b, point c) {
    int dx1 = a.first - c.first, dy1 = a.second - c.second;
    int dx2 = b.first - c.first, dy2 = b.second - c.second;
    return dx1 * dy2 - dx2 * dy1;
}
bool cmp(const point& a, const point& b) {
    if (a == mn) return true;
    if (b == mn) return false;
    return cross(a, b, mn) >= 0;
}
void convex_hull(vector<point>& cur) {
    mn = cur[0];
    FOR(i, cur.size()) {
        if (cur[i].second < mn.second || (cur[i].second == mn.second && cur[i].first < mn.first))
            mn = cur[i];
    }
    sort(cur.begin(), cur.end(), cmp);
    hull.clear();
    hull.push_back(cur[0]);
    hull.push_back(cur[1]);
    cur.push_back(cur[0]);
    for (int i = 2; i < cur.size(); ++i) {
        while (hull.size() > 1 && cross(cur[i], hull[hull.size() - 2], hull[hull.size() - 1]) <= 0) hull.pop_back();
        hull.push_back(cur[i]);
    }
    hull.pop_back();
    return;
}
int main() {
    int n;
    scanf("%d", &n);
    vector<point> g(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &g[i].first, &g[i].second);
    }
    convex_hull(g);
    double res = 0;
    int sz = hull.size();
    for (int i = 0; i < sz; ++i) {
        int ptr1 = i, ptr2 = (i + 1) % sz;
        int j = (i + 1) % sz;
        while (j != i) {
            while (abs(cross(hull[i], hull[j], hull[ptr1])) < abs(cross(hull[i], hull[j], hull[(ptr1 + 1) % sz]))) {
                ptr1 = (ptr1 + 1) % sz;
            }
            while (abs(cross(hull[i], hull[j], hull[ptr2])) < abs(cross(hull[i], hull[j], hull[(ptr2 + 1) % sz]))) {
                ptr2 = (ptr2 + 1) % sz;
            }
            res = max(res, 1.0 * abs(cross(hull[i], hull[j], hull[ptr1]))
                            + 1.0 * abs(cross(hull[i], hull[j], hull[ptr2])));
            j = (j + 1) % sz;
        }
    }
    res = res / 2.0;
    printf("%.3f\n", res);
    return 0;
}
