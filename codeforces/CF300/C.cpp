#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> h(m), day(m);
    FOR(i, m) {
        cin >> day[i] >> h[i];
    }
    int res = *max_element(h.begin(), h.end());
    FOR(i, m - 1) {
        int dday = day[i + 1] - day[i];
        int dh = h[i + 1] - h[i];
        if (abs(dh) > dday) { cout << "IMPOSSIBLE" << endl; return 0; }
        if (dh >= 0) {
            res = max(res, (dday - dh) / 2 + h[i + 1]);
        }
        else res = max(res, (dday + dh) / 2 + h[i]);
    }
    res = max(res, day[0] - 1 + h[0]);
    res = max(res, n - day[m - 1] + h[m - 1]);
    cout << res << endl;
    return 0;
}
