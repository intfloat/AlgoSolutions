#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, T;
    scanf("%d %d", &n, &T);
    vector<ll> cap(n), tem(n);
    FOR(i, n) scanf("%I64d", &cap[i]);
    FOR(i, n) scanf("%I64d", &tem[i]);
    vector<pair<int, int> > data;
    FOR(i, n) data.push_back({tem[i], cap[i]});
    sort(data.begin(), data.end());
    double left = 0, right = accumulate(cap.begin(), cap.end(), (double)0);
    int cnt = 0;
    while (right - left > 1e-9 && cnt < 100) {
        ++cnt;
        double mid = (right - left) / 2 + left;
        double target = mid * (double)T;
        double cur_cap = 0, mul = 0;
        for (int i = 0; i < n; ++i) {
            if (data[i].second + cur_cap < mid) {
                cur_cap += data[i].second;
                mul += (double)data[i].second * (double)data[i].first;
            } else {
                mul += (double)(mid - cur_cap) * (double)data[i].first;
                cur_cap += mid - cur_cap;
                break;
            }
            if (mul > target) break;
        }
        bool forward = (mul <= target);
        cur_cap = 0; mul = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (data[i].second + cur_cap < mid) {
                cur_cap += data[i].second;
                mul += (double)data[i].second * (double)data[i].first;
            } else {
                mul += (double)(mid - cur_cap) * (double)data[i].first;
                cur_cap += mid - cur_cap;
                break;
            }
            if (mul > target) break;
        }
        bool backward = (mul >= target);
        if (forward && backward) {
            left = mid;
        } else {
            right = mid;
        }
    }
    printf("%.9lf\n", (right + left) / 2);
    return 0;
}
