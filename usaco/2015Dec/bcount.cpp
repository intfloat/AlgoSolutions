#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<int> num[3];
inline int query(int id, int l, int r) {
    return num[id][r] - num[id][l - 1];
}
int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int N, Q, l, r, id;
    scanf("%d %d", &N, &Q);
    FOR(i, 3) {
        num[i].resize(N + 1);
        fill(num[i].begin(), num[i].end(), 0);
    }
    FOR(i, N) {
        scanf("%d", &id);
        ++num[id - 1][i + 1];
    }
    FOR(i, 3) {
        for (int j = 1; j <= N; ++j) {
            num[i][j] += num[i][j - 1];
        }
    }
    FOR(i, Q) {
        scanf("%d %d", &l, &r);
        printf("%d %d %d\n", query(0, l, r), query(1, l, r), query(2, l, r));
    }
    return 0;
}
