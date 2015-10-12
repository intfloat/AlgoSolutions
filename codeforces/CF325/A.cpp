#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n), d(n), p(n), res;
    vector<bool> out(n, false);
    FOR(i, n) scanf("%d %d %d", &v[i], &d[i], &p[i]);
    FOR(i, n) {
        if (p[i] >= 0) {
            res.push_back(i);
            for (int j = i + 1; j < n && v[i]; ++j) {
                if (!out[j] && p[j] >= 0) {
                    p[j] -= v[i];
                    --v[i];
                }
            }
            for (int j = i + 1; j < n; ++j) {
                if (!out[j] && p[j] < 0) {
                    out[j] = true;
                    for (int k = j + 1; k < n; ++k) {
                        if (p[k] >= 0) p[k] -= d[j];
                    }
                }
            }
        }
    }
    printf("%d\n", (int)res.size());
    FOR(i, res.size()) printf("%d ", res[i] + 1);
    printf("\n");
    return 0;
}
