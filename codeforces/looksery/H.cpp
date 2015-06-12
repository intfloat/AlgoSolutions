#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
typedef pair<double, double> point;
const int dir_x[] = {1, 1, -1, -1};
const int dir_y[] = {-1, 1, 1, -1};
double cross(point& a, point& b) {
    return a.first * b.second - a.second * b.first;
}
bool check(point& p1, vector<point>& p2) {
    bool cc[2];
    cc[0] = cc[1] = false;
    for (int i = 0; i < 4; ++i) {
        double dt = cross(p1, p2[i]);
        if (fabs(dt) < 1e-20) return true;
        if (dt < 0) cc[0] = true;
        else cc[1] = true;
    }
    return cc[0] && cc[1];
}
int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    double left = 0, right = 1e10;
    vector<point> p1(4), p2(4);
    int cnt = 0;
    while (right - left > 1e-11 && cnt++ < 1000) {
        double mid = (right + left) * 0.5;
        FOR(i, 4) {
            p1[i] = make_pair(a + mid * dir_x[i], b + mid * dir_y[i]);
            p2[i] = make_pair(c + mid * dir_x[i], d + mid * dir_y[i]);
        }
        bool ok = false;
        FOR(i, 4) {
            if (check(p1[i], p2) || check(p2[i], p1)) {
                ok = true;
                break;
            }
        }
        if (ok) right = mid;
        else left = mid + 1e-12;
    }
    printf("%.11lf\n", 0.5 * (left + right));
    return 0;
}
