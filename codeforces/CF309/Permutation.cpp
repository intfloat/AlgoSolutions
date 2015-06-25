#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
    ll n, k;
    cin >> n >> k;
    ll dp[55][2];
    dp[1][1] = 0; dp[1][0] = 1;
    dp[2][1] = 1; dp[2][0] = 1;
    for (int i = 3; i <= n; ++i) {
        dp[i][1] = dp[i - 2][0] + dp[i - 2][1];
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
    }
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        res[i] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        int cnt = n - i;
        if (k > dp[cnt][0]) {
            k -= dp[cnt][0];
            swap(res[i], res[i + 1]);
            ++i;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
