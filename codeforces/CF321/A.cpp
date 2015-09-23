#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    FOR(i, n) scanf("%d", &arr[i]);
    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i) {
        if (arr[i] >= arr[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        }
    }
    printf("%d\n", *max_element(dp.begin(), dp.end()));
    return 0;
}
