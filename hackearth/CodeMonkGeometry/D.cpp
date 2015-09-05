#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef pair<double, double> point;
vector<double> x, y;
vector<point> arr;
double H;
const double INF = 1e14;
int N;
inline double euclidean(const point& a, const point& b) {
    double dx = a.first - b.first;
    double dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}
inline double cross(const point& a, const point& b, const point& c) {
    double x1 = a.first - c.first, y1 = a.second - c.second;
    double x2 = b.first - c.first, y2 = b.second - c.second;
    return x1 * y2 - x2 * y1;
}
inline bool ok(const point& a, const point& b, int l, int r) {
    l -= l % 2; r -= r % 2;
    if (l != r) {
        double slope = (b.second - a.second) / (b.first - a.first);
        for (int i = l; i <= r; i += 2) {
            double val = a.second + slope * (arr[i].first - a.first);
            if (val < arr[i].second - 1e-8 || val > arr[i].second + H + 1e-8) {
                return false;
            }
        }
    }
    for (int i = 0; i + 2 < arr.size(); ++i) {
        if (cross(a, b, arr[i]) * cross(a, b, arr[i + 2]) < -1e-8
            && cross(arr[i], arr[i + 2], a) * cross(arr[i], arr[i + 2], b) < -1e-8) {
            return false;
        }
    }
    return true;
}
int main() {
    scanf("%d", &N);
    ++N;
    x.resize(N); y.resize(N);
    FOR(i, N) {
        scanf("%lf %lf", &x[i], &y[i]);
    }
    scanf("%lf", &H);
    FOR(i, N) {
        arr.push_back(make_pair(x[i], y[i]));
        arr.push_back(make_pair(x[i], y[i] + H));
    }
    int S = 2 * N, T = 2 * N + 1;
    double dis[210][210];
    FOR(i, 210) FOR(j, 210) dis[i][j] = INF;
    FOR(i, T + 1) dis[i][i] = 0;
    FOR(i, arr.size()) for (int j = i + 1; j < arr.size(); ++j) {
        if (ok(arr[i], arr[j], i, j)) {
            dis[i][j] = dis[j][i] = euclidean(arr[i], arr[j]);
        }
    }
    FOR(i, arr.size()) {
        point ss = make_pair(x[0], arr[i].second);
        if (arr[i].second >= y[0] && arr[i].second <= y[0] + H && ok(ss, arr[i], 0, i)) {
            dis[i][S] = dis[S][i] = euclidean(ss, arr[i]);
        }
    }
    FOR(i, arr.size()) {
        point tt = make_pair(x.back(), arr[i].second);
        if (arr[i].second >= y.back() && arr[i].second <= y.back() + H && ok(tt, arr[i], i, arr.size() - 1)) {
            dis[i][T] = dis[T][i] = euclidean(tt, arr[i]);
        }
    }
    // run dijkstra algorithm
    vector<double> res(T + 1, INF);
    vector<bool> visited(T + 1, false);
    res[S] = 0;
    while (true) {
        double mn = INF;
        int idx = -1;
        FOR(i, T + 1) {
            if (!visited[i] && res[i] < mn) {
                mn = res[i];
                idx = i;
            }
        }
        if (idx == T) {
            cout << fixed << setprecision(10) << res[T] << endl;
            return 0;
        }
        assert(idx >= 0);
        visited[idx] = true;
        FOR(i, T + 1) {
            res[i] = min(res[i], res[idx] + dis[idx][i]);
        }
    }
    return 0;
}
