// this code got Wrong Answer, but i think it is absolutely correct...
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
    Point() {}
    Point(double _x, double _y): x(_x), y(_y) {}
};

struct Line {
    Point from, to;
    double a, b, c;
    Line(Point _from, Point _to): from(_from), to(_to) {
        a = to.y - from.y;
        b = from.x - to.x;
        c = -(a * from.x + b * from.y);
    }
};

Line trans(Line ln, double d) {
    double dx = d * (ln.to.y - ln.from.y) / sqrt(ln.a * ln.a + ln.b * ln.b);
    double dy = d * (ln.from.x - ln.to.x) / sqrt(ln.a * ln.a + ln.b * ln.b);
    Point p1(ln.from.x + dx, ln.from.y + dy);
    Point p2(ln.to.x + dx, ln.to.y + dy);
    return Line(p1, p2);
}

int n;
double x, y, r;
vector<Line> lns;
vector<Point> v;
const double eps = 0;

Point l_inter_s(Point from, Point to, Line ln) {
    double w1 = fabs(from.x * ln.a + from.y * ln.b + ln.c);
    double w2 = fabs(to.x * ln.a + to.y * ln.b + ln.c);
    x = (from.x * w2 + to.x * w1) / (w1 + w2);
    y = (from.y * w2 + to.y * w1) / (w1 + w2);
    return Point(x, y);
}

void halfPlaneCross() {
    FOR(i, n) {
        double a = lns[i].a, b = lns[i].b, c = lns[i].c;
        vector<Point> res;
        FOR(j, v.size()) {
            double val = a * v[j].x + b * v[j].y + c;
            double nv = a * v[(j + 1) % v.size()].x + b * v[(j + 1) % v.size()].y + c;
            if (val >= 0 && nv >= 0) res.push_back(v[j]);
            else if (val >= 0 && nv < 0) {
                res.push_back(v[j]);
                res.push_back(l_inter_s(v[j], v[(j + 1) % v.size()], lns[i]));
            }
            else if (val < 0 && nv >= 0)
                res.push_back(l_inter_s(v[j], v[(j + 1) % v.size()], lns[i]));
        }
        v = res;
    }
    return;
}

int main() {
    cin >> n >> r;
    FOR(i, n) {
        cin >> x >> y;
        v.push_back(Point(x, y));
    }
    FOR(i, n) {
        lns.push_back(Line(v[i], v[(i + 1) % n]));
        lns[i] = trans(lns[i], r);
    }

    halfPlaneCross();
    double mx = -1;
    int p1 = 0, p2 = 0;
    FOR(i, v.size()) for (int j = i; j < v.size(); ++j) {
        double dx = v[j].x - v[i].x;
        double dy = v[j].y - v[i].y;
        // if (sqrt(dx * dx + dy * dy) > 29.31)
        // cout << fixed << setprecision(7) << v[i].x << " " << v[i].y << " " << v[j].x << " " << v[j].y
        // << " " << sqrt(dx * dx + dy * dy) << endl;
        if (dx * dx + dy * dy > mx) {
            mx = dx * dx + dy * dy;
            p1 = i; p2 = j;
        }
    }
    // assert(mx >= 0);
    // cout << "distance: " << sqrt(mx) << endl;
    cout << fixed << setprecision(7)
         << v[p1].x << " " << v[p1].y << " "
         << v[p2].x << " " << v[p2].y << endl;
    return 0;
}
