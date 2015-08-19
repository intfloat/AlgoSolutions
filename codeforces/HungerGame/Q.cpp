#include <bits/stdc++.h>
using namespace std;
int dp[145], pv[145];
inline void preprocess() {
    memset(dp, 0, sizeof dp);
    dp[1] = 0;
    for (int i = 2; i <= 144; ++i) {
        int mn = 300;
        for (int j = 1; j < i; ++j) {
            int cur = max(2 + dp[j], 1 + dp[i - j]);
            if (cur < mn) {
                mn = cur;
                pv[i] = j;
            }
        }
        dp[i] = mn;
    }
}
int main() {
    preprocess();
    int n, mx;
    scanf("%d", &n);
    if (n < dp[144]) {
        printf("Not enough money\n");
        return 0;
    }
    printf("Let's play!\n");
    int l = 1, r = 144;
    while (true) {
        if (l == r) {
            printf("0 %d\n", l);
            return 0;
        }
        int t = r - l + 1;
        int mx = pv[t] + l - 1;
        printf("%d ", pv[t]);
        for (int i = l; i <= mx; ++i) {
            printf("%d ", i);
        }
        printf("\n");
        fflush(stdout);
        char cc[10];
        scanf("%s", &cc);
        if (strcmp(cc, "Yes") == 0) {
            r = mx;
        }
        else if (strcmp(cc, "No") == 0) {
            l = mx + 1;
        }
        else {
            assert(false);
        }
    }
    return 0;
}
