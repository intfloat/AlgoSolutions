#include <stdio.h>
// F(x) = 6 * x^7+8*x^6+7*x^3+5*x^2-y*x
// F'(x) = 42 * x^6 + 48 * x^5 + 21 * x^2 + 10*x - y
using namespace std;
inline double pw(double x, int p) {
    double ret = 1;
    for (int i = 0; i < p; ++i) {
        ret *= x;
    }
    return ret;
}
inline double f(double x, double y) {
    return 6 * pw(x, 7) + 8 * pw(x, 6) + 7 * pw(x, 3) + 5 * pw(x, 2) - y * x;
}
inline double df(double x, double y) {
    return 42 * pw(x, 6) + 48 * pw(x, 5) + 21 * pw(x, 2) + 10 * x - y;
}
void solve() {
    double y;
    scanf("%lf", &y);
    double l = 0, r = 100;
    int cnt = 0;
    while (r - l > 1e-7 && cnt++ < 200) {
        double mid = (l + r) / 2;
        if (df(mid, y) < 0) l = mid;
        else r = mid;
    }
    printf("%.4f\n", f((l + r) / 2, y));
}
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}
