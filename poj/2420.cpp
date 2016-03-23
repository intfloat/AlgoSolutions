#include <stdio.h>
#include <vector>
#include <utility>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;
int N;
vector<pii> arr;
const double delta = 0.99;
inline double calc(double x, double y) {
    double ret = 0;
    for (int i = 0; i < N; ++i) {
        double dx = x - arr[i].first, dy = y - arr[i].second;
        ret += sqrt(dx * dx + dy * dy);
    }
    return ret;
}
int main() {
    srand(1234);
    scanf("%d", &N);
    arr.resize(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }
    double T = 100;
    double x = arr[0].first, y = arr[0].second;
    double res = calc(x, y);
    while (T > 1e-4) {
        for (int i = 0; i < 100; ++i) {
            double dx = (2.0 * rand() / RAND_MAX - 1) * T;
            double dy = (2.0 * rand() / RAND_MAX - 1) * T;
            double cur = calc(x + dx, y + dy);
            if (cur < res) {
                res = cur;
                x += dx;
                y += dy;
            }
        }
        T *= delta;
    }
    printf("%.0f\n", res);
    return 0;
}
