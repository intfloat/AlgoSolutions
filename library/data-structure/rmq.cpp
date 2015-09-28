#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 50005;
int val[MAX_N], dp[MAX_N][20], N;
inline void rmq_init() {
    for (int i = 0; i < N; ++i) {
        dp[i][0] = val[i];
    }
    for (int i = 1; (1 << i) <= N; ++i) {
        for (int j = 0; (j + (1 << i) - 1) < N; ++j) {
            dp[j][i] = max(dp[j][i - 1], dp[j + (1 << (i - 1))][i - 1]);
        }
    }
}
inline int query(int left, int right) {
    int k = 0;
    int length = right - left + 1;
    while ((1 << (k + 1)) < length) ++k;
    int ret = max(dp[left][k], dp[right - (1 << k) + 1][k]);
    return ret;
}

int main() {
    return 0;
}
