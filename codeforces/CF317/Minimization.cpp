#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (ll)(1e15);
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> arr(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr.begin() + 1, arr.end());
    int sz = n / k;
    int extra = n - sz * k;
    vector<vector<ll> > dp(k + 1, vector<ll>(extra + 1, INF));
    dp[0][0] = 0;
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j <= extra && j <= i; ++j) {
            int idx = sz * i + j;
            if (j - 1 < 0) {
                dp[i][j] = dp[i - 1][j] + arr[idx] - arr[idx - sz + 1];
            }
            else {
                dp[i][j] = min(dp[i - 1][j] + arr[idx] - arr[idx - sz + 1],
                           dp[i - 1][j - 1] + arr[idx] - arr[idx - sz]);
            }
        }
    }
    cout << dp[k][extra] << endl;
    return 0;
}
