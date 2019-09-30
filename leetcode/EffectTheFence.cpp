#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef pair<int, int> point;
vector<point> hull;
point mn;
inline int cross(const point& a, const point& b, const point& c) {
    int dx1 = a.first - c.first, dy1 = a.second - c.second;
    int dx2 = b.first - c.first, dy2 = b.second - c.second;
    return dx1 * dy2 - dx2 * dy1;
}
inline int squared_distance(const point& a, const point& b) {
    int dx = a.first - b.first, dy = a.second - b.second;
    return dx * dx + dy * dy;
}
bool cmp(const point& a, const point& b) {
    if (a == mn) return true;
    if (b == mn) return false;
    int m = cross(a, b, mn);
    if (m == 0) {
        return squared_distance(a, mn) < squared_distance(b, mn);
    } else {
        return m > 0;
    }
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

bool inhull(point& p) {
    FOR(i, hull.size()) {
        point p1 = hull[i];
        point p2 = hull[(i + 1) % hull.size()];
        if (cross(p1, p2, p) == 0) return true;
    }
    return false;
}

class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        if (points.size() <= 3) {
            return points;
        }
        vector<point> ps;
        for (auto& p : points) {
            ps.push_back({p[0], p[1]});
        }
        vector<vector<int>> res;
        convex_hull(ps);
        for (auto& p : points) {
            point pt = {p[0], p[1]};
            if (inhull(pt)) {
                res.push_back(p);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}