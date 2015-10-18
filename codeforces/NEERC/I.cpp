#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, k, c;
    scanf("%d %d", &n, &k);
    vector<int> cnt(k + 1, 0);
    FOR(i, n) {
        scanf("%d", &c);
        ++cnt[c];
    }
    int avg = n / k;
    int res = 0;
    for (int i = 1; i <= k; ++i) {
        if (cnt[i] < avg) res += avg - cnt[i];
    }
    printf("%d\n", res);
    return 0;
}
