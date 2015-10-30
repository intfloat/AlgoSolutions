#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int dp[32];
int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < 32; ++i) dp[i] = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        int val = 1, cnt = 0, mx = -1;
        vector<int> arr;
        while (val <= x && cnt < 32) {
            if (val & x) {
                arr.push_back(cnt);
                ++dp[cnt];
                mx = max(mx, dp[cnt]);
            }
            ++cnt;
            val <<= 1;
        }
        for (int j = 0; j < (int)arr.size(); ++j) {
            dp[arr[j]] = mx;
        }
    }
    for (int i = 1; i < 32; ++i) {
        dp[0] = max(dp[0], dp[i]);
    }
    printf("%d\n", dp[0]);
}
