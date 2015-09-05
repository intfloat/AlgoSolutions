#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<double, double> point;
inline point get(double xm, double ym, point& p) {
    point ret = make_pair(xm, ym);
    ret.first -= 2 * p.first;
    ret.second -= 2 * p.second;
    return ret;
}
inline void solve() {
    vector<point> arr(3);
    double xm = 0, ym = 0;
    FOR(i, 3) {
        cin >> arr[i].first >> arr[i].second;
        xm += arr[i].first;
        ym += arr[i].second;
    }
    vector<point> res;
    FOR(i, 3) {
        res.push_back(get(xm, ym, arr[i]));
    }
    sort(res.begin(), res.end());
    FOR(i, 3) {
        cout << fixed << setprecision(4) << res[i].first << " " << res[i].second << endl;
    }
}
int main() {
    solve();
    return 0;
}
