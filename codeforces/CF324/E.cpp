#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n), c(n + 1);
    FOR(i, n) scanf("%d", &a[i]);
    FOR(i, n) scanf("%d", &b[i]);
    FOR(i, n) c[b[i]] = i;
    FOR(i, n) a[i] = c[a[i]];
    vector<pii> res;
    int cost = 0;
    for (int i = n - 1; i >= 0; --i) {
        int pos = find(a.begin(), a.end(), i) - a.begin();
        if (pos == i) continue;
        int ptr = pos + 1;
        while (a[i] != i) {
            while (a[ptr] > pos) ++ptr;
            swap(a[pos], a[ptr]);
            res.push_back({pos, ptr});
            cost += abs(pos - ptr);
            pos = ptr;
            ++ptr;
        }
    }
    printf("%d\n", cost);
    printf("%d\n", (int)res.size());
    FOR(i, res.size()) printf("%d %d\n", res[i].first + 1, res[i].second + 1);
    return 0;
}
