// by xyz111
#include <cstdio>
#include <algorithm>
using namespace std;

struct aa {
    int x, y, w;
} a[1100];

int T, n;
long long dp[2100], ans, dp1[2100];

bool cmp(aa a, aa b) {
    return a.x - a.y < b.x - b.y;
}

int main() {
    // freopen("a.in", "r", stdin);
    scanf("%d", &T);
    for (int mm1 = 1; mm1 <= T; mm1++) {
        printf("Case #%d: ", mm1);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].w);
            a[i].w *= 4;
        }
        sort(a + 1, a + n + 1, cmp);
        for (int i = 0; i <= 2000; i++)
            dp[i] = -1e17;
        for (int i = 1; i <= n; i++) {
            long long t = a[i].w - a[i].y * a[i].y * 4;
            for (int j = 0; j <= 2000; j++)
                dp1[j] = -1e17;
            dp1[a[i].x + a[i].y] = t;
            for (int j = 0; j <= 2000; j++) {

                if (j <= a[i].x - a[i].y) t = dp[j] + a[i].w - a[i].y * a[i].y * 4;
                else if (j >= a[i].x + a[i].y) t = dp[j] + a[i].w;
                else t = dp[j] + a[i].w - a[i].y * a[i].y * 4 + (j - a[i].x + a[i].y) * (j - a[i].x + a[i].y);
                dp1[max(a[i].x + a[i].y, j)] = max(dp1[max(a[i].x + a[i].y, j)], t);
            }

            for (int j = 0; j <= 2000; j++)
                dp[j] = max(dp[j], dp1[j]);
        }
        ans = 0;
        for (int i = 0; i <= 2000; i++)
            ans = max(ans, dp[i]);
        if (ans % 4 == 0)
            printf("%lld.00\n", ans / 4);
        else if (ans % 4 == 1)
            printf("%lld.25\n", ans / 4);
        else if (ans % 4 == 2)
            printf("%lld.50\n", ans / 4);
        else    printf("%lld.75\n", ans / 4);
    }
}
