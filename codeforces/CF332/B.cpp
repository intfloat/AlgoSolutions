#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> A(m + 1, -1), B(m + 1), f(n + 1);
    vector<vector<int> > cnt(n + 1, vector<int>());
    FOR(i, n) {
        scanf("%d", &f[i + 1]);
        cnt[f[i + 1]].push_back(i + 1);
    }
    bool amb = false;
    FOR(i, m) {
        int x;
        scanf("%d", &x);
        if (cnt[x].empty()) {
            printf("Impossible\n");
            return 0;
        }
        else if (cnt[x].size() > 1) {
            amb = true;
        }
        else {
            A[i + 1] = cnt[x][0];
        }
    }
    if (amb) printf("Ambiguity\n");
    else {
        printf("Possible\n");
        FOR(i, m) {
            printf("%d ", A[i + 1]);
        }
        printf("\n");
    }
    return 0;
}
