#include <cstdio>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <deque>
#include <thread>

using namespace std;

const int mod = 1000000007;

long long dp[2][4][252][252];
char dat[512];

void add(long long &dest, long long val)
{
    dest = (dest+val) % mod;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int testcase = 1; testcase <= T; testcase++)
    {
        fprintf(stderr, "Case #%d processing\n", testcase);
        scanf("%s",dat);
        int n = strlen(dat);
        long long ans = 0;
        memset(dp,0,sizeof(dp));
        dp[0][0][0][0] = 1;
        for (int i = 0; i < n; i++) {
            int ci = i&1;
            int ni = !ci;
            memcpy(dp[ni], dp[ci], sizeof(dp[ci]));
            for (int state = 0; state < 4; state++) {
                for (int c1 = 0; c1 <= 250; c1++) {
                    for (int c2 = 0; c2 <= 250; c2++) {
                        auto cur =dp[ci][state][c1][c2];
                        if (cur==0)continue;
                        if (dat[i] == 'a') {
                            if (state == 0) {
                                add(dp[ni][state][c1+1][c2], cur);
                            }
                        } else if (dat[i] == 'b') {
                            if (state == 0) {
                                add(dp[ni][1][c1][1], cur);
                            } else if (state == 1) {
                                add(dp[ni][1][c1][c2+1], cur);
                            }
                        } else if (dat[i] == 'c') {
                            if (state == 1) {
                                if (c1 >= 2) {
                                    add(dp[ni][2][c1-1][c2],cur);
                                } else if (c1 == 1) {
                                    add(dp[ni][3][c1-1][c2],cur);
                                }
                            } else if (state == 2) {
                                if (c1 >= 2) {
                                    add(dp[ni][2][c1-1][c2],cur);
                                } else if (c1 == 1) {
                                    add(dp[ni][3][c1-1][c2],cur);
                                }
                            }
                        } else {
                            if (state == 3) {
                                if (c2 >= 2) {
                                    add(dp[ni][3][c1][c2-1],cur);
                                } else if (c2 == 1) {
                                    add(dp[ni][0][0][0],cur);
                                    add(ans, cur);
                                }
                            }
                        }
                    }
                }
            }
        }
        ans = (ans%mod+mod)%mod;
        printf("Case #%d: %lld\n",testcase, ans);
    }
    return 0;
}
