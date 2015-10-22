#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 8005;
bool dp[4][MAX_N];
void solve() {
    memset(dp, false, sizeof dp);
    vector<bool> prime(MAX_N, true);
    vector<int> arr;
    queue<pii> q;
    for (int i = 2; i < MAX_N; ++i) {
        if (prime[i]) {
            arr.push_back(i);
            q.push(make_pair(i, 0));
            dp[0][i] = true;
            for (int j = i * i; j < MAX_N; j += i) {
                prime[j] = false;
            }
        }
    }
    while (!q.empty()) {
        pii tp = q.front(); q.pop();
        int cur = tp.first;
        int step = tp.second;
        if (step == 3) continue;
        FOR(i, arr.size()) {
            int nval = (cur | arr[i]);
            if (nval >= MAX_N) continue;
            if (!dp[step + 1][nval]) {
                dp[step + 1][nval] = true;
                q.push(make_pair(nval, step + 1));
            }
        }
    }
}
int main() {
    int T, N;
    solve();
    scanf("%d", &T);
    FOR(i, T) {
        scanf("%d", &N);
        if (dp[3][N]) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
