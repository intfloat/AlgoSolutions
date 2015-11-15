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
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef double ll;
typedef pair<ll, ll> point;
vector<point> hull;
point mn;
inline ll cross(point a, point b, point c) {
    ll dx1 = a.first - c.first, dy1 = a.second - c.second;
    ll dx2 = b.first - c.first, dy2 = b.second - c.second;
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
    for (int i = 2; i < (int)cur.size(); ++i) {
        while (hull.size() > 1 && cross(cur[i], hull[hull.size() - 2], hull[hull.size() - 1]) <= 0) hull.pop_back();
        hull.push_back(cur[i]);
    }
    hull.pop_back();
    return;
}
ll dis(point& a, point& b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
inline void solve() {
    vector<point> arr(5);
    FOR(i, 5) {
        cin >> arr[i].first >> arr[i].second;
    }
    double mx = 0;
    FOR(i, 5) FOR(j, 5) {
        mx = max(mx, dis(arr[i], arr[j]));
    }
    if (mx < 1e-4) {
        printf("Yes\n");
        return;
    }
    convex_hull(arr);
    if ((int)hull.size() != 5) {
        printf("No\n");
    }
    else {
        hull.push_back(hull[0]);
        ll d = dis(hull[0], hull[1]);
        FOR(i, 5) {
            if (fabs(d - dis(hull[i], hull[i + 1])) > 1e-4) {
                printf("No\n");
                return;
            }
        }
        printf("Yes\n");
    }
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
