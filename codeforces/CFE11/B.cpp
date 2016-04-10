#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > g(n, vector<int>(4, -1));
    int ptr = 0;
    FOR(i, n) {
        if (ptr < m) g[i][0] = ptr++;
        if (ptr < m) g[i][3] = ptr++;
    }
    FOR(i, n) {
        if (ptr < m) g[i][1] = ptr++;
        if (ptr < m) g[i][2] = ptr++;
    }
    FOR(i, n) {
        if (g[i][1] >= 0) printf("%d ", g[i][1] + 1);
        if (g[i][0] >= 0) printf("%d ", g[i][0] + 1);
        if (g[i][2] >= 0) printf("%d ", g[i][2] + 1);
        if (g[i][3] >= 0) printf("%d ", g[i][3] + 1);
    }
    printf("\n");
    return 0;
}
