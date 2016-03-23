#include <stdio.h>
#include <vector>
#include <utility>
#include <limits.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int X, Y, M;
vector<pii> arr;
const double delta = 0.98;
inline double calc(double x, double y) {
    double ret = 1e10;
    for (int i = 0; i < M; ++i) {
        double dx = (x - arr[i].first), dy = (y - arr[i].second);
        ret = min(ret, dx * dx + dy * dy);
    }
    return ret;
}
void solve() {
    scanf("%d %d %d", &X, &Y, &M);
    arr.resize(M);
    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }
    double T = max(X, Y);
    double cx = rand() % (X + 1), cy = rand() % (Y + 1);
    double res = calc(cx, cy);
    while (T > 1e-4) {
        for (int i = 0; i < 100; ++i) {
            double dx = (2.0 * rand() / RAND_MAX - 1.0) * T;
            double dy = (2.0 * rand() / RAND_MAX - 1.0) * T;
            if (cx + dx < 0 || cx + dx > X || cy + dy < 0 || cy + dy > Y) continue;
            double tmp = calc(cx + dx, cy + dy);
            if (tmp > res) {
                cx += dx;
                cy += dy;
                res = tmp;
            }
        }
        T *= delta;
    }
    printf("The safest point is (%.1f, %.1f).\n", cx, cy);
}
int main() {
    int T;
    srand(789);
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}
