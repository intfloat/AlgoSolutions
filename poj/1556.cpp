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
using namespace std;

struct Point {
    double x, y;
    Point(double _x, double _y): x(_x), y(_y) {}
    Point() {}
};

struct Line {
    Point p1, p2;
    Line(Point _p1, Point _p2): p1(_p1), p2(_p2) {}
    Line() {}
};

double cross(Point a, Point b1, Point b2) {
    return (b1.x - a.x) * (b2.y - a.y) - (b1.y - a.y) * (b2.x - a.x);
}

bool intersect(Line a, Line b) {
    Point pa1 = a.p1, pa2 = a.p2;
    Point pb1 = b.p1, pb2 = b.p2;
    return max(pa1.x, pa2.x) > min(pb1.x, pb2.x)
        && max(pb1.x, pb2.x) > min(pa1.x, pa2.x)
        && max(pa1.y, pa2.y) > min(pb1.y, pb2.y)
        && max(pb1.y, pb2.y) > min(pa1.y, pa2.y)
        && cross(pa1, pa2, pb1) * cross(pa1, pa2, pb2) < 0
        && cross(pb1, pb2, pa1) * cross(pb1, pb2, pa2) < 0; 
}

double euclidean(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) 
                + (p1.y - p2.y) * (p1.y - p2.y));
}

vector<Line> v;
vector<Point> ps;
const int MAX_N = 80;
double dis[MAX_N][MAX_N];
int main() {
    int N, M;
    while (cin >> N && N >= 0) {
        v.clear(); ps.clear();
        ps.push_back(Point(0, 5));
        ps.push_back(Point(10, 5));
        double x, y;
        Point p[4];
        for (int i = 0; i < N; ++i) {
            cin >> x;
            for (int j = 0; j < 4; ++j) { cin >> y; p[j] = Point(x, y); ps.push_back(Point(x, y)); }
            v.push_back(Line(Point(x, 0), p[0]));
            v.push_back(Line(p[1], p[2]));
            v.push_back(Line(p[3], Point(x, 10)));
        }
        int T = ps.size();
        for (int i = 0; i < T; ++i)
        for (int j = 0; j < T; ++j) {
            if (i == j) dis[i][j] = 0;
            else dis[i][j] = INT_MAX;
        }
        for (int i = 0; i < T; ++i)
        for (int j = 0; j < i; ++j) {
            Line l(ps[i], ps[j]);
            bool ok = true;
            for (int k = 0; k < v.size(); ++k) {
                if (intersect(v[k], l)) { ok = false; break; }
            }
            if (ok) {
                dis[i][j] = min(dis[i][j], euclidean(ps[i], ps[j]));
                dis[j][i] = min(dis[j][i], euclidean(ps[i], ps[j]));
            }
        }

        // floyd is easier to implement
        for (int k = 0; k < T; ++k)
        for (int i = 0; i < T; ++i)
        for (int j = 0; j < T; ++j) {
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
        cout << fixed << setprecision(2) << dis[0][1] << endl;
    }
    return 0;
}
