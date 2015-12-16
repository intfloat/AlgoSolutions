#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    int T, A, B;
    scanf("%d %d %d", &T, &A, &B);
    vector<vector<bool> > orange(2, vector<bool>(T + 1, false));
    vector<vector<bool> > lemon(2, vector<bool>(T + 1, false));
    for (int i = 0; i <= T; i += A) {
        orange[0][i] = true;
    }
    FOR(i, T + 1) {
        if (i - A >= 0) orange[1][i] = orange[1][i] || orange[1][i - A];
        if (i * 2 <= T) orange[1][i] = orange[1][i] || orange[0][i * 2];
        if (i * 2 + 1 <= T) orange[1][i] = orange[1][i] || orange[0][i * 2 + 1];
    }
    FOR(i, T + 1) {
        lemon[0][i] = orange[0][i];
        if (i - B >= 0) lemon[0][i] = lemon[0][i] || lemon[0][i - B];
    }
    FOR(i, T + 1) {
        lemon[1][i] = orange[1][i];
        if (i - B >= 0) lemon[1][i] = lemon[1][i] || lemon[1][i - B];
        if (i * 2 <= T) lemon[1][i] = lemon[1][i] || lemon[0][i * 2];
        if (i * 2 + 1 <= T) lemon[1][i] = lemon[1][i] || lemon[0][i * 2 + 1];
    }
    for (int i = T; i >= 0; --i) {
        if (lemon[0][i] || lemon[1][i]) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
