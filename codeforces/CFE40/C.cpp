#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> pos(n);
    FOR(i, n) scanf("%d", &pos[i]);
    int mx = *max_element(pos.begin(), pos.end());

    int column = -1;
    FOR(i, n - 1) {
        int diff = abs(pos[i] - pos[i + 1]);
        if (diff == 0) {
            printf("NO\n");
            return 0;
        } else if (diff != 1 && column < 0) {
            column = diff;
        } else if (diff != 1 && column > 0 && diff != column) {
            printf("NO\n");
            return 0;
        }
    }
    if (column < 0) {
        printf("YES\n");
        printf("%d 1\n", mx);
        return 0;
    }
    // we need to check again
    FOR(i, n - 1) {
        int diff = abs(pos[i] - pos[i + 1]);
        if (diff == 1 && (pos[i] - 1) / column != (pos[i + 1] - 1) / column) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    printf("%d %d\n", (mx + column - 1) / column, column);
    return 0;
}
