#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
double X1, Y1, x2, y2, vm, vx, vy, wx, wy, t;
inline bool check(double mid) {
    double x, y;
    if (mid > t) {
        x = x2 - t * vx - (mid - t) * wx;
        y = y2 - t * vy - (mid - t) * wy;
    }
    else {
        x = x2 - mid * vx;
        y = y2 - mid * vy;
    }
    double dis = sqrt(x * x + y * y);
    return vm * mid >= dis;
}
int main() {
    cin >> X1 >> Y1 >> x2 >> y2;
    x2 -= X1; y2 -= Y1;
    cin >> vm >> t;
    cin >> vx >> vy >> wx >> wy;
    double l = 0, r = 1e15;
    int cnt = 0;
    while (r - l > 1e-9 && ++cnt < 100) {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    printf("%.10lf\n", l);
    return 0;
}
