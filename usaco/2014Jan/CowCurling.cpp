#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < int(n); ++i)
using namespace std;

typedef long long ll;
typedef pair<ll, ll> point;
int N;

ll cross(const point& a, const point& b, const point& c) {
    ll x1 = b.first - a.first, x2 = c.first - a.first;
    ll y1 = b.second - a.second, y2 = c.second - a.second;
    return x1 * y2 - x2 * y1;
}

bool intersect(point& a1, point& a2, point& b1, point& b2) {    
    if (cross(a2, b1, b2) == 0) return false;    
    if (cross(a1, b1, b2) * cross(a2, b1, b2) < 0
        && cross(b1, a1, a2) * cross(b2, a1, a2) < 0
        && min(a1.first, a2.first) <= max(b1.first, b2.first)
        && min(a1.second, a2.second) <= max(b1.second, b2.second)
        && min(b1.first, b2.first) <= max(a1.first, a2.first)
        && min(b1.second, b2.second) <= max(a1.second, a2.second)) return true;    
    return false;
}

vector<point> convex_hull(vector<point>& ps) {
    vector<int> res;
    res.resize(ps.size() + 1);
    res[0] = 0; res[1] = 1;
    assert(ps.size() > 2);
    int ptr = 1;
    ps.push_back(ps[0]);
    for (int i = 2; i < static_cast<int>(ps.size()); ++i) {
        while (ptr >= 1 && cross(ps[res[ptr]], ps[i], ps[res[ptr - 1]]) <= 0) {
            --ptr;
        }
        if (i != ps.size() - 1) res[++ptr] = i;
    }
    ps.pop_back();
    res.resize(ptr + 1);    
    vector<point> td(ptr + 1);
    FOR(i, td.size()) td[i] = ps[res[i]];
    if (td.size() == 1) td.push_back(ps.back());
    return td;
}

int search(vector<point>& hull, point& p) {    
    int left = 1, right = static_cast<int>(hull.size()) - 1;    
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        if (cross(hull[0], hull[mid], p) >= 0) left = mid;
        else right = mid - 1;
    }
    assert(left <= right);    
    if (cross(hull[0], hull[right], p) >= 0) return right;
    else return left;
}

int solve(vector<point>& as, vector<point>& bs) {    
    vector<point> hull = convex_hull(as);
    int res = 0;
    FOR(i, bs.size()) {
        if (bs[i] < hull[0]) continue;
        if (cross(hull[0], bs[i], hull[1]) > 0) continue;
        if (cross(hull[0], hull.back(), bs[i]) > 0) continue;
        if (cross(hull[0], hull.back(), bs[i]) == 0) {
            res += (bs[i].second <= hull.back().second);
            continue;
        }
        if (bs[i] == hull[0]) { ++res; continue; }
        int pos = search(hull, bs[i]);        
        assert(pos + 1 < (int)hull.size());
        res += (intersect(hull[0], bs[i], hull[pos], hull[pos + 1]) == false);        
    }
    return res;
}

point mn;
bool cmp(const point& p1, const point& p2) {
    ll t = cross(mn, p1, p2);
    if (t != 0) return (t > 0);
    else return (p1.first < p2.first);
}
int main() {
    freopen("curling.in", "r", stdin);
    freopen("curling.out", "w", stdout);
    vector<point> as, bs;
    cin >> N;
    as.resize(N); bs.resize(N);
    FOR(i, N) cin >> as[i].first >> as[i].second;
    FOR(i, N) cin >> bs[i].first >> bs[i].second;
    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());
    mn = as[0]; sort(as.begin() + 1, as.end(), cmp);
    mn = bs[0]; sort(bs.begin() + 1, bs.end(), cmp);    
    cout << solve(as, bs) << " " << solve(bs, as) << endl;  
    return 0;
}
