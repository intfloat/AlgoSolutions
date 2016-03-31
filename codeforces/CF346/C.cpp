#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> has(n);
    FOR(i, n) scanf("%d", &has[i]);
    sort(has.begin(), has.end(), greater<int>());
    int cost = 0, cur = 1;
    vector<int> res;
    while (cost <= m) {
        if (cost + cur > m) break;
        else if (!has.empty() && has.back() == cur) {
            has.pop_back();
            ++cur;
        }
        else {
            res.push_back(cur);
            cost += cur;
            ++cur;
        }
    }
    printf("%d\n", (int)res.size());
    FOR(i, res.size()) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}
