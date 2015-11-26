#include <stdio.h>
#include <iostream>
#include <utility>
#include <vector>
#include <string.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
long long seed, n, q;
vector<int> a;
const int MAX_N = 10000005;
int cnt[MAX_N];
int rand(int l, int r) {
    static long long mo=1e9+7, g=78125;
    return l+((seed*=g)%=mo)%(r-l+1);
}
inline void solve() {
    cin >> n >> q >> seed;
    a.resize(n + 1);
    int sum=rand(q, 10000000);
    for(int i=1; i<=n; i++) {
        a[i]=rand(0, sum/(n-i+1));
        sum-=a[i];
    }
    a[rand(1, n)]+=sum;
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; ++i) {
        ++cnt[a[i]];
    }
    int ptr = MAX_N - 1;
    for (; ptr > 0; --ptr) {
        if (q == 0) break;
        if (q < cnt[ptr]) {
            cnt[ptr] -= q;
            cnt[ptr - 1] += q;
            break;
        }
        else {
            q -= cnt[ptr];
            cnt[ptr - 1] += cnt[ptr];
            cnt[ptr] = 0;
        }
    }
    while (cnt[ptr] == 0) --ptr;
    int tot = cnt[ptr];
    int res = 0;
    for (int i = n; i >= 1; --i) {
        if (a[i] < ptr) {
            res ^= (a[i] + i);
        }
        else if (tot > 0) {
            --tot;
            res ^= (ptr + i);
        }
        else res ^= (ptr - 1 + i);
    }
    cout << res << endl;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
