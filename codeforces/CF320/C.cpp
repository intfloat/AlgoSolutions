#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
vector<long double> narr;
vector<int> arr;
inline int grad(long double& x) {
    long double mn = 0, mx = 0;
    int p1 = 0, p2 = 0;
    long double val = 0;
    for (int i = 1; i < (int)narr.size(); ++i) {
        val += (long double)arr[i - 1] - x;
        if (val < mn) {
            mn = val;
            p1 = i;
        }
        if (val > mx) {
            mx = val;
            p2 = i;
        }
    }
    if (p1 < p2) return -1;
    else if (p1 > p2) return 1;
    else return 0;
}
inline long double get(long double val) {
    long double mn = 0, mx = 0;
    for (int i = 1; i < (int)narr.size(); ++i) {
        mn = min(mn, narr[i] - val * i);
        mx = max(mx, narr[i] - val * i);
    }
    return mx - mn;
}
int main() {
    int n;
    scanf("%d", &n);
    arr.resize(n);
    FOR(i, n) scanf("%d", &arr[i]);
    narr.push_back(0.0);
    FOR(i, n) narr.push_back(arr[i]);
    FOR(i, n) narr[i + 1] = narr[i] + arr[i];
    double l = -1e4, r = 1e4;
    int cnt = 0;
    while (++cnt < 200) {
        long double mid = (r + l) / 2.0;
        int g = grad(mid);
        if (g < 0) l = mid;
        else if (g >= 0) r = mid;
        else {
            l = r = mid;
            break;
        }
    }
    long double res = get((l + r) / 2.0);
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}
