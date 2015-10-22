#include <bits/stdc++.h>

using namespace std;

#define int int64_t
const int n = 16, maxn = 1 << n;
int dp[n + 1][maxn][2][3];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> posib[n];
    for(int i = 0; i < 16; i++)
    {
        int m;
        cin >> m;
        posib[i].resize(m);
        for(int j = 0; j < m; j++)
            cin >> posib[i][j];
    }
    dp[0][0][0][2] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < posib[i].size(); j++)
        {
            if(posib[i][j] == 0)
            {
                for(int k = 0; k < maxn; k++)
                    if((k & 1) == 0)
                    {
                        dp[i + 1][k ^ 1][0][(i / 4 + 1) % 2] += dp[i][k][0][2],
                        dp[i + 1][k ^ 1][1][(i / 4 + 1) % 2] += dp[i][k][1][2];
                    }
            }
            else
            {
                int z = posib[i][j];
                for(int k = 0; k < maxn; k++)
                {
                    if((k >> z) & 1)
                        continue;
                    int t = __builtin_popcount(k >> z) % 2;
                    for(int l = 0; l < 3; l++)
                        dp[i + 1][k ^ (1 << z)][t][l] += dp[i][k][0][l],
                        dp[i + 1][k ^ (1 << z)][t ^ 1][l] += dp[i][k][1][l];
                }

            }
        }
    }
    int ans = 0;
    for(int i = 0; i < maxn; i++)
        ans += dp[n][i][0][0] + dp[n][i][1][1];
    cout << ans << "\n";
    return 0;
}
