#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);    
    vector<vector<int> > det(n, vector<int>(m));
    vector<deque<pair<int, int> > > q(m, deque<pair<int, int> >());
    vector<int> res(m, 0);

    FOR(i, n) FOR(j, m) scanf("%d", &det[i][j]);
    FOR(i, m) q[i].push_front(make_pair(det[0][i], 0));
    int mx = -1, prev = 0;

    for (int i = 1; i <= n; ++i) {
        while (true) {
            bool ok = true;
            int val = 0, mn = INT_MAX;
            FOR(j, m) assert(!q[j].empty());
            FOR(j, m) val += q[j].front().first;
            FOR(j, m) mn = min(mn, q[j].front().second);            
            if (val > k) {
                prev = mn + 1;
                FOR(j, m) {
                    if (q[j].front().second == mn) {
                        q[j].pop_front();
                        if (q[j].empty()) { ok = false; break; }
                    }
                }
                if (!ok) break;
            }
            else {
                if (i - prev > mx) {
                    mx = i - prev;
                    FOR(j, m) res[j] = q[j].front().first;
                }
                break;
            }
        }

        // push new element in
        if (i == n) break;
        FOR(j, m) {
            int number = det[i][j];
            // maintain an non-increasing monotonic queue
            while (!q[j].empty() && number > q[j].back().first) q[j].pop_back();
            q[j].push_back(make_pair(number, i));
        }
    }
    if (mx == -1) res[0] = k; // longest consecutive sequence is 0
    FOR(i, res.size()) printf("%d ", res[i]);
    printf("\n");
    return 0;
}
