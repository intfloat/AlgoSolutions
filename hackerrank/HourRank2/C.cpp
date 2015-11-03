#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int g[5][5];
int main() {
    int N, d1, d2;
    scanf("%d", &N);
    FOR(i, 5) FOR(j, 5) g[i][j] = INT_MAX / 10;
    FOR(i, 5) {
        scanf("%d %d", &d1, &d2);
        int pos = (i + 1) % 5;
        g[i][pos] = d1;
        pos = (pos + 1) % 5;
        g[i][pos] = d2;
    }
    vector<vector<int> > dp(5, vector<int>(N + 1, -1));
    queue<pii> q;
    q.push({0, 0});
    vector<int> ans;
    while (!q.empty()) {
        pii& tp = q.front(); q.pop();
        int pos = tp.first, dis = tp.second;
        FOR(i, 5) {
            if (i != pos) {
                int val = dis + g[pos][i];
                if (val <= N && dp[i][val] < 0) {
                    dp[i][val] = pos;
                    if (val == N) {
                        int idx = i, cur = val;
                        while (cur > 0) {
                            ans.push_back(idx);
                            int tmp = cur;
                            cur -= g[dp[idx][cur]][idx];
                            idx = dp[idx][tmp];
                        }
                        ans.push_back(0);
                        reverse(ans.begin(), ans.end());
                        FOR(j, ans.size()) printf("%d ", ans[j] + 1);
                        printf("\n");
                        return 0;
                    }
                    q.push({i, val});
                }

            }
        }
    }
    printf("-1\n");
    return 0;
}
