#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
double get(double a, double b, double c) {
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
int main() {
    double arr[6];
    FOR(i, 6) {
        cin >> arr[i];
    }
    double c1 = sqrt(arr[0] * arr[0] + arr[1] * arr[1] + arr[0] * arr[1]);
    double c2 = sqrt(arr[2] * arr[2] + arr[3] * arr[3] + arr[2] * arr[3]);
    double c3 = sqrt(arr[4] * arr[4] + arr[5] * arr[5] + arr[4] * arr[5]);
    double area = 0;
    area += get(arr[0], arr[1], c1);
    area += get(arr[2], arr[3], c2);
    area += get(arr[4], arr[5], c3);
    area += get(c1, c2, c3);
    int res = (int)(area * 4.0 / sqrt(3.0));
    cout << res << endl;
    return 0;
}
