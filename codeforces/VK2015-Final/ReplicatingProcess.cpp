#include <bits/stdc++.h>
using namespace std;
vector<int> val;
vector<int> a, b, c;
inline bool ok(int pos) {
    --val[a[pos]];
    ++val[b[pos]];
    ++val[c[pos]];
    if (val[a[pos]] >= 0 && val[b[pos]] <= 9 && val[c[pos]] <= 9) {
        return true;
    }
    ++val[a[pos]];
    --val[b[pos]];
    --val[c[pos]];
    return false;
}
int main() {
    int n;
    scanf("%d", &n);
    val.resize(n + 1);
    a.resize(4 * n + 1);
    b.resize(4 * n + 1);
    c.resize(4 * n + 1);
    fill(val.begin(), val.end(), 4);
    for (int i = 1; i <= 4 * n; ++i) {
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
    }
    vector<bool> visited(4 * n + 1, false);
    vector<int> res;
    int cnt = 0;
    while (cnt < 4 * n) {
        bool has = false;
        for (int j = 1; j <= 4 * n; ++j) {
            if (!visited[j] && ok(j)) {
                has = true;
                visited[j] = true;
                res.push_back(j);
                ++cnt;
            }
        }
        if (!has) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    for (int i = 0; i < res.size(); ++i) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}
