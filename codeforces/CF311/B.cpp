#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    int n, w;
    scanf("%d %d", &n, &w);
    vector<int> cap(2 * n);
    FOR(i, 2 * n) {
        scanf("%d", &cap[i]);
    }
    sort(cap.begin(), cap.end());
    double res = cap[0];
    res = min(res, (double)cap[n] / 2) * 3 * n;
    res = min(res, 1.0 * w);
    cout << fixed << setprecision(8) << res << endl;
    return 0;
}
