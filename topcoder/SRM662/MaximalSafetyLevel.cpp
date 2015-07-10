#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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

using namespace std;

typedef pair<double, double> point;
inline double norm(point& a, point& b) {
    double x = a.first - b.first;
    double y = a.second - b.second;
    return sqrt(x * x + y * y);
}
inline double cross(point& a, point& b, point& c) {
    double x1 = a.first - c.first, x2 = b.first - c.first;
    double y1 = a.second - c.second, y2 = b.second - c.second;
    return x1 * y2 - x2 * y1;
}
inline double dot(point& a, point& b, point& c) {
    double x1 = a.first - c.first, x2 = b.first - c.first;
    double y1 = a.second - c.second, y2 = b.second - c.second;
    return x1 * x2 + y1 * y2;
}
inline double dis(point& a, point& b) {
    double dx = a.first - b.first;
    double dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}
class Flee {
public:
    double maximalSafetyLevel(vector <int>, vector <int>);
};

double Flee::maximalSafetyLevel(vector <int> x, vector <int> y) {
    vector<point> arr;
    int sz = x.size();
    for (int i = 0; i < sz; ++i) {
        arr.push_back(make_pair(1.0 * x[i], 1.0 * y[i]));
    }
    point start = make_pair(0.0, 0.0);
    double res = norm(start, arr[0]);
    for (int i = 1; i < sz; ++i) {
        res = min(res, norm(start, arr[i]));
    }
    if (sz <= 2) {
        return res;
    }
    bool neg[3];
    for (int i = 0; i < 3; ++i) {
        // origin on the edge of triangle
        if (fabs(cross(arr[i], arr[(i + 1) % 3], start)) < 1e-10) {
            return res;
        }
        neg[i] = (cross(arr[i], arr[(i + 1) % 3], start) < 0);
    }
    for (int i = 0; i < 3; ++i) {
        // origin is located outside triangle
        if (neg[i] != neg[(i + 1) % 3]) {
            return res;
        }
    }
    vector<double> cand(3);
    // origin is inside triangle
    for (int i = 0; i < 3; ++i) {
        point& a = arr[i];
        point& b = arr[(i + 1) % 3];
        point mid = make_pair(0.5 * (a.first + b.first), 0.5 * (a.second + b.second));
        double d1 = dis(mid, a);
        double d2 = dis(start, a);
        cand[i] = min(res, d1);
    }
    res = *max_element(cand.begin(), cand.end());
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
