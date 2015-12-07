#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
inline int f(int x) {
    return (1890 * x + 143) % 10007;
}
int main() {
    int n;
    vector<int> arr, dp;
    while (scanf("%d", &n) != EOF) {
        arr.resize(n);
        int sm = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
            sm += arr[i];
        }
        dp.resize(n);
        dp[0] = f(arr[0]) - arr[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = f(arr[i]) - arr[i] + max(0, dp[i - 1]);
        }
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, dp[i]);
        }
        printf("%d\n", sm + mx);
    }
    return 0;
}
