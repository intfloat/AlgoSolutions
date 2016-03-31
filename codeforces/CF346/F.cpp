#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
#define ID(r, c) r * col + c
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 1000005;
int fa[MAX_N], cnt[MAX_N];
const int dir_x[] = {0, 0, 1, -1};
const int dir_y[] = {1, -1, 0, 0};
int _find(int pos) {
    if (fa[pos] != pos) {
        fa[pos] = _find(fa[pos]);
    }
    return fa[pos];
}
int mx = 0, ridx = -1;
void merge(int i, int j) {
    int ri = _find(i), rj = _find(j);
    if (ri == rj) return;
    fa[rj] = ri;
    cnt[ri] += cnt[rj];
    if (cnt[ri] > mx) {
        mx = cnt[ri];
        ridx = i;
    }
}
int main() {
    memset(cnt, 0, sizeof cnt);
    int row, col;
    ll k;
    cin >> row >> col >> k;
    vector<vector<int> > g(row, vector<int>(col));
    FOR(i, row) FOR(j, col) scanf("%d", &g[i][j]);
    vector<pii> arr;
    FOR(i, row) FOR(j, col) arr.push_back({g[i][j], ID(i, j)});
    sort(arr.begin(), arr.end(), greater<pii>());
    int ptr = 0;
    while (ptr < row * col) {
        int i = ptr;
        mx = 1; ridx = arr[ptr].second;
        while (i < (int)arr.size() && arr[i].first == arr[ptr].first) {
            int idx = arr[i].second;
            int r = idx / col, c = idx % col;
            fa[idx] = idx; cnt[idx] = 1;
            FOR(j, 4) {
                int nr = r + dir_x[j], nc = c + dir_y[j];
                if (nr < 0 || nr >= row || nc < 0 || nc >= col) {
                    continue;
                }
                if (cnt[ID(nr, nc)] > 0) {
                    merge(idx, ID(nr, nc));
                }
            }
            ++i;
        }
        if (k % arr[ptr].first == 0 && (ll)mx >= k / (ll)arr[ptr].first) {
            printf("YES\n");
            vector<vector<bool> > used(row, vector<bool>(col, false));
            int r = ridx / col, c = ridx % col;
            queue<pii> q; q.push({r, c});
            used[r][c] = true;
            int tot = k / arr[ptr].first - 1;
            while (tot > 0) {
                pii tp = q.front(); q.pop();
                FOR(j, 4) {
                    int nr = tp.first + dir_x[j], nc = tp.second + dir_y[j];
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col || used[nr][nc] || g[nr][nc] < g[r][c]) {
                        continue;
                    }
                    used[nr][nc] = true;
                    --tot;
                    if (tot == 0) break;
                    q.push({nr, nc});
                }
            }
            FOR(ii, row) {
                FOR(jj, col) {
                    if (used[ii][jj]) printf("%d ", arr[ptr].first);
                    else printf("0 ");
                }
                printf("\n");
            }
            return 0;
        }
        else {
            ptr = i;
        }
    }
    printf("NO\n");
    return 0;
}
