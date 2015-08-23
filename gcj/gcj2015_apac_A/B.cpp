#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> point;
void solve() {
    int N, Q, l, r;
    cin >> N >> Q;
    vector<double> arr(N);
    FOR(i, N) cin >> arr[i];
    FOR(i, Q) {
        cin >> l >> r;
        long double cur = 0.0;
        for (int j = l; j <= r; ++j) {
            cur += log(arr[j]);
        }
        long double low = 0.0, up = 1e10;
        int cnt = 0;
        while (cnt < 1000) {
            ++cnt;
            long double mid = (low + up) / 2.0;
            long double val = (long double)(r - l + 1) * log(mid);
            if (val > cur) up = mid;
            else low = mid;
        }
        cout << fixed << setprecision(10) << (low + up) / 2.0 << endl;
    }
    return;
}
int main() {
    int TestCase;
    cin >> TestCase;
    FOR(caseID, TestCase) {
        cout << "Case #" << caseID + 1 << ":" << endl;
        solve();
    }
    return 0;
}
