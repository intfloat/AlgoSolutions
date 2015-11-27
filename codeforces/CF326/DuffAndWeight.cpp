#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 1001005;
int cnt[MAX_N];
int main() {
    int n, x;
    scanf("%d", &n);
    FOR(i, n) {
        scanf("%d", &x);
        ++cnt[x];
    }
    int res = 0;
    FOR(i, MAX_N) {
        if (cnt[i] && cnt[i] % 2 == 0) {
            cnt[i + 1] += cnt[i] / 2;
            cnt[i] = 0;
        }
        else if (cnt[i] % 2) {
            ++res;
            cnt[i + 1] += cnt[i] / 2;
            cnt[i] = 0;
        }
    }
    printf("%d\n", res);
    return 0;
}
