#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
inline void solve() {
    int N;
    scanf("%d", &N);
    vector<int> arr(N);
    FOR(i, N) scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());
    int mx = arr[N - 3] + arr[N - 2] + arr[N - 1];
    vector<int> cube;
    for (int i = 1; i * i * i <= mx; ++i) {
        cube.push_back(i * i * i);
    }
    ll total = (ll)N * (ll)(N - 1) * (ll)(N - 2) / 6ll;
    ll cnt = 0;
    FOR(i, N) for (int j = i + 1; j + 1 < N; ++j) {
        int low = arr[i] + arr[j] + arr[j + 1];
        int up = arr[i] + arr[j] + arr[N - 1];
        int pos = lower_bound(cube.begin(), cube.end(), low) - cube.begin();
        while (pos < cube.size() && cube[pos] <= up) {
            int diff = cube[pos] - arr[i] - arr[j];
            int idx = lower_bound(arr.begin() + j + 1, arr.end(), diff) - arr.begin();
            if (idx < N && arr[idx] == diff) {
                int r = upper_bound(arr.begin() + idx, arr.end(), diff) - arr.begin();
                cnt += (r - idx);
            }
            ++pos;
        }
    }
    double prob = (double)cnt / total;
    cout << fixed << setprecision(9) << prob << endl;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
