#include <vector>
#include <list>
#include <limits.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

struct Point {
    int x, y;
    Point(int _x, int _y): x(_x), y(_y) {}
    Point() {}
};
Point base;
vector<Point> points;

int cross(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

int dist(const Point& a, const Point& b) {
    return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

bool cmp(const Point& a, const Point& b) {
    int res = cross(base, a, b);
    return (res > 0) || (res == 0 && dist(base, a) < dist(base, b));
}

vector<Point> convexHull() {
    // int pos = 0;
    base = points[0];
    FOR(i, points.size()) {
        if (points[i].y < base.y || (points[i].y == base.y && points[i].x < base.x))
            base = points[i];
    }
    sort(points.begin(), points.end(), cmp);
    stack<Point> s;
    s.push(points[0]); s.push(points[1]);
    for (int i = 2; i < points.size(); ++i) {
        while(true) {
            Point p2 = s.top(); s.pop();
            if (s.empty()) { s.push(p2); s.push(points[i]); break; }
            Point p1 = s.top();
            if (cross(p2, p1, points[i]) >= 0) continue;
            else { s.push(p2); s.push(points[i]); break; }
        }
    }
    vector<Point> res;
    while (!s.empty()) {
        res.push_back(s.top());
        s.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int P, N, t;
int main() {
    cin >> P;
    while (P--) {
        cin >> t >> N;
        points.clear();
        FOR(i, N) { Point p; cin >> p.x >> p.y; points.push_back(p); }
        vector<Point> res = convexHull();
        int pos = 0; Point ans = res[0];
        FOR(i, res.size()) {
            if (res[i].y > ans.y || (res[i].y == ans.y && res[i].x < ans.x)) {
                pos = i;
                ans = res[i];
            }
        }
        cout << t << " " << res.size() << endl;
        for (int i = pos; i >= 0; --i) cout << res[i].x << " " << res[i].y << endl;
        for (int i = res.size() - 1; i > pos; --i) cout << res[i].x << " " << res[i].y << endl;
    }
    return 0;
}
