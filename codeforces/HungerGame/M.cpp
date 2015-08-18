#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int val[MAXN], dp[MAXN][20], N;
int res[MAXN][20];
inline void rmq_init() {
    for (int i = 0; i < N; ++i)
        dp[i][0] = val[i];
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
    int mx = max(dp[left][k], dp[right - (1 << k) + 1][k]);
    return mx;
}
inline void update(int pos, int num) {
    res[pos][0] = num;
    for (int i = 1; pos - (1 << i) + 1 >= 0; ++i) {
        int low = pos - (1 << i) + 1;
        res[low][i] = max(res[low][i - 1], res[low + (1 << (i - 1))][i - 1]);
    }
}
inline int query2(int left, int right) {
    int k = 0;
    int length = right - left + 1;
    while ((1 << (k + 1)) < length) ++k;
    int mx = max(res[left][k], res[right - (1 << k) + 1][k]);
    return mx;
}
int main() {
    int t, m, type, l, r;
    scanf("%d %d", &N, &m);
    for (int i = 0; i < N; ++i) {
        scanf("%d", val + i);
    }
    rmq_init();
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &type, &l, &r);
        --l; --r;
        if (type == 1) t = query(l, r);
        else t = query2(l, r);
        update(i, t);
        printf("%d\n", t);
    }
    return 0;
}
