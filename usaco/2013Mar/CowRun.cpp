#include <stdio.h>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <functional>
using namespace std;
const int INF = INT_MAX / 2;
int dp[1001][1001][2];
int main() {
#ifndef DEBUG
    freopen("cowrun.in", "r", stdin);
    freopen("cowrun.out", "w", stdout);
#endif
    int N, num;
    scanf("%d", &N);
    vector<int> pos, neg;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &num);
        if (num < 0) neg.push_back(num);
        else pos.push_back(num);
    }
    neg.push_back(0);
    pos.push_back(0);
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), greater<int>());
    int ns = neg.size() - 1;
    int ps = pos.size() - 1;
    dp[0][0][0] = dp[0][0][1] = 0;
    for (int i = 1; i <= ps; ++i) {
        dp[0][i][1] = dp[0][i - 1][1] + (pos[i] - pos[i - 1]) * (N - i + 1);
        dp[0][i][0] = INF;
    }
    for (int i = 1; i <= ns; ++i) {
        dp[i][0][0] = dp[i - 1][0][0] + (neg[i - 1] - neg[i]) * (N - i + 1);
        dp[i][0][1] = INF;
    }
    for (int i = 1; i <= ns; ++i) {
        for (int j = 1; j <= ps; ++j) {
            int rem = N - i - j + 1;
            dp[i][j][0] = min(dp[i - 1][j][0] + (neg[i - 1] - neg[i]) * rem,
                              dp[i - 1][j][1] + (pos[j] - neg[i]) * rem);
            dp[i][j][1] = min(dp[i][j - 1][1] + (pos[j] - pos[j - 1]) * rem,
                              dp[i][j - 1][0] + (pos[j] - neg[i]) * rem);
        }
    }
    int res = min(dp[ns][ps][0], dp[ns][ps][1]);
    printf("%d\n", res);
    return 0;
}
