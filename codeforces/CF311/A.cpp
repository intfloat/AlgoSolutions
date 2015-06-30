#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    int n;
    cin >> n;
    int mn[3], mx[3], d[3], res[3];
    FOR(i, 3) {
        cin >> mn[i] >> mx[i];
        d[i] = mx[i] - mn[i];
    }
    n = n - mn[0] - mn[1] - mn[2];
    FOR(i, 3) {
        if (n > d[i]) {
            res[i] = mx[i];
            n -= d[i];
        }
        else {
            res[i] = mn[i] + n;
            n = 0;
        }
    }
    FOR(i, 3) cout << res[i] << " ";
    cout << endl;
    return 0;
}
