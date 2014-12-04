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
    double x, y;
    Point(double _x, double _y): x(_x), y(_y) {}
    Point() {}
    Point(const Point& _p): x(_p.x), y(_p.y) {}
};

struct Line {
    Point from, to;
    double a, b, c;
    // Line(double _a, double _b, double _c): a(_a), b(_b), c(_c) {}
    Line(Point _from, Point _to): from(_from), to(_to) {
        a = to.y - from.y;
        b = from.x - to.x;
        c = -(a * from.x + b * from.y);
    }
};

Point l_inter_s(const Point& p1, const Point& p2, const Line& ln) {
    double d1 = fabs(p1.x * ln.a + p1.y * ln.b + ln.c);
    double d2 = fabs(p2.x * ln.a + p2.y * ln.b + ln.c);
    double xx = (p1.x * d2 + p2.x * d1) / (d1 + d2);
    double yy = (p1.y * d2 + p2.y * d1) / (d1 + d2);
    return Point(xx, yy);
}

Line trans(const Line& ln, double r) {
    Point p1 = ln.from, p2 = ln.to;
    double dx = r * (p2.y - p1.y) / sqrt(ln.a * ln.a + ln.b * ln.b);
    double dy = r * (p1.x - p2.x) / sqrt(ln.a * ln.a + ln.b * ln.b);
    return Line(Point(p1.x + dx, p1.y + dy), Point(p2.x + dx, p2.y + dy));
}

vector<Point> points;
const double eps = 1e-7;
vector<Point> halfPlaneCross(const vector<Line>& lines) {
    vector<Point> cur = points;
    vector<Point> res = cur;
    FOR(i, lines.size()) {
        res.clear();
        FOR(j, cur.size()) {
            Point np = cur[(j + 1) % cur.size()];
            double d1 = lines[i].a * cur[j].x + lines[i].b * cur[j].y + lines[i].c;
            double d2 = lines[i].a * np.x + lines[i].b * np.y + lines[i].c;
            if (d1 > eps && d2 > eps) res.push_back(cur[j]);
            else if (d1 > eps && d2 < -eps) {
                res.push_back(cur[j]);
                res.push_back(l_inter_s(cur[j], np, lines[i]));
            }
            else if (d1 < -eps && d2 > eps)
                res.push_back(l_inter_s(cur[j], np, lines[i]));
        }
        // FOR(j, res.size()) cout << res[j].x << " " << res[j].y << endl;
        // cout << "=====================" << endl;
        cur = res;
    }
    return res;
}

bool check(double r) {
    vector<Line> lines;
    FOR(i, points.size()) {
        Line ln(points[i], points[(i + 1) % points.size()]);
        lines.push_back(trans(ln, r));
    }
    return (halfPlaneCross(lines).size() > 0);
}

int main() {
    int N;
    while (cin >> N && N) {
        points.clear();
        FOR(i, N) {
            double x, y;
            cin >> x >> y;
            points.push_back(Point(x, y));
        }
        reverse(points.begin(), points.end());
        double left = 0, right = 1e5;
        while (left + 1e-8 < right) {
            double mid = (left + right) / 2;
            if (check(mid)) left = mid;
            else right = mid;
        }
        cout << fixed << setprecision(7) << right << endl;
    }
    return 0;
}
