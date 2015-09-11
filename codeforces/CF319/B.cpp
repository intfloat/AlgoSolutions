#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> p(n + 1);
    FOR(i, n) scanf("%d", &p[i + 1]);
    vector<bool> visited(n + 1, false);
    vector<vector<int> > arr;
    vector<int> sz;
    for (int i = 1; i <= n; ++i) {
        if (visited[i]) continue;
        vector<int> cur;
        cur.push_back(i);
        visited[i] = true;
        int ptr = p[i];
        while (ptr != i) {
            cur.push_back(ptr);
            visited[ptr] = true;
            ptr = p[ptr];
        }
        sz.push_back(cur.size());
        arr.push_back(cur);
    }
    int mn = *min_element(sz.begin(), sz.end());
    if (mn == 1) {
        printf("YES\n");
        int pos = -1;
        FOR(i, sz.size()) {
            if (sz[i] == 1) { pos = i; break; }
        }
        for (int i = 1; i <= n; ++i) {
            if (i != arr[pos][0]) printf("%d %d\n", arr[pos][0], i);
        }
    }
    else if (mn == 2) {
        FOR(i, sz.size()) {
            if (sz[i] % 2) {
                printf("NO\n");
                return 0;
            }
        }
        printf("YES\n");
        int pos = -1;
        FOR(i, sz.size()) {
            if (sz[i] == 2) { pos = i; break; }
        }
        int x = arr[pos][0], y = arr[pos][1];
        printf("%d %d\n", x, y);
        FOR(i, arr.size()) {
            if (i == pos) continue;
            FOR(j, arr[i].size()) {
                if (j % 2 == 0) printf("%d %d\n", x, arr[i][j]);
                else printf("%d %d\n", y, arr[i][j]);
            }
        }
    }
    else {
        printf("NO\n");
    }
    return 0;
}
