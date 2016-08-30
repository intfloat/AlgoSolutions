#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n;
    scanf("%d", &n);
    vector<vector<ll> > arr(n, vector<ll>(n));
    int r, c;
    FOR(i, n) FOR(j, n) {
        cin >> arr[i][j];
        if (0 == arr[i][j]) {
            r = i; c = j;
        }
    }
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    ll sm = 0;
    if (r == 0) {
        sm = accumulate(arr[1].begin(), arr[1].end(), 0ll);
    } else {
        sm = accumulate(arr[0].begin(), arr[0].end(), 0ll);
    }
    ll res = sm - accumulate(arr[r].begin(), arr[r].end(), 0ll);
    arr[r][c] = res;
    if (res <= 0) {
        printf("-1\n");
        return 0;
    }
    FOR(i, n) {
        if (sm != accumulate(arr[i].begin(), arr[i].end(), 0ll)) {
            printf("-1\n");
            return 0;
        }
        ll cur = 0;
        FOR(j, n) cur += arr[j][i];
        if (cur != sm) {
            printf("-1\n");
            return 0;
        }
    }
    ll t = 0, p = 0;
    FOR(i, n) t += arr[i][i];
    FOR(i, n) p += arr[i][n - 1 - i];
    if (sm != t || sm != p) {
        printf("-1\n");
        return 0;
    }
    cout << res << endl;
    return 0;
}
