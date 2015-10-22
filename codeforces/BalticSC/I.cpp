#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    double r, R, h;
    cin >> r >> R >> h;
    double left = 0, right = min(h / 2, R);
    int cnt = 0;
    double side = sqrt(h * h + (R - r) * (R - r));
    while (fabs(right - left) > 1e-10 && ++cnt < 100) {
        double mid = (right + left) / 2;
        double area = R * h - (R - r) * mid;
        double nh = area / side;
        if (nh > mid) left = mid;
        else right = mid;
    }
    printf("%.10lf\n", left);
    return 0;
}
