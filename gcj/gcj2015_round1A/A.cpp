#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

int main() {
    int T, N;
    cin >> T;
    FOR(tt, T) {
        cin >> N;
        vector<int> cakes(N);
        FOR(i, N) cin >> cakes[i];
        cout << "Case #" << tt + 1 << ": ";
        int res1 = 0, mx = -1, res2 = 0;
        FOR(i, N - 1) {
            res1 += max(cakes[i] - cakes[i + 1], 0);
            mx = max(mx, cakes[i] - cakes[i + 1]);
        }
        if (mx <= 0) res2 = 0;
        else {
            FOR(i, N - 1) {
                if (cakes[i] < mx) res2 += cakes[i];
                else res2 += mx;
            }
        }
        cout << res1 << " " << res2 << endl;
    }
    return 0;
}
