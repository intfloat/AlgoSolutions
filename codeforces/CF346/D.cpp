#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<double, double> point;
const double PI = 2.0 * acos(0.0);
inline double cross(point& a, point& b, point& c) {
    double dx1 = a.first - c.first, dy1 = a.second - c.second;
    double dx2 = b.first - c.first, dy2 = b.second - c.second;
    return dx1 * dy2 - dx2 * dy1;
}
inline double dot(point& a, point& b, point& c) {
    double dx1 = a.first - c.first, dy1 = a.second - c.second;
    double dx2 = b.first - c.first, dy2 = b.second - c.second;
    double rr = (dx1 * dx2 + dy1 * dy2) / sqrt(dx1 * dx1 + dy1 * dy1) / sqrt(dx2 * dx2 + dy2 * dy2);
    rr = acos(rr);
    if (cross(a, b, c) < 0) return -rr;
    else return rr;
}
int n;
vector<point> arr;
inline bool check(point& cur) {
    double cc = 0;
    FOR(i, n) {
        point p2 = arr[i];
        point p3 = arr[(i + 1) % n];
        cc += dot(p2, p3, cur);
    }
    return !(fabs(cc) < 1e-5);
}
int main() {
    int res = 0, x, y;
    scanf("%d", &n);
    arr.resize(n + 1);
    FOR(i, n + 1) {
        scanf("%d %d", &x, &y);
        arr[i].first = x;
        arr[i].second = y;
    }
    arr.pop_back();
    FOR(i, n) {
        point& a = arr[i];
        point& b = arr[(i + 1) % n];
        point cur;
        if (a.first == b.first) {
            if (a.second < b.second) cur = make_pair(a.first, b.second + 0.5);
            else cur = make_pair(a.first, b.second - 0.5);
        }
        else if (a.second == b.second) {
            if (a.first < b.first) cur = make_pair(b.first + 0.5, a.second);
            else cur = make_pair(b.first - 0.5, a.second);
        }
        res += check(cur);
    }
    printf("%d\n", res);
    return 0;
}
