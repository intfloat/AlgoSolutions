#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll fac[20];
bool ok(ll num, int pos) {
    if (pos == 2) {
        if (__builtin_popcountll(num) == 1) return true;
        else return false;
    }
    if (num < fac[pos]) return ok(num, pos - 1);
    else if (num % fac[pos]) return ok(num, pos - 1);
    else return ok(num / fac[pos], pos) || ok(num, pos - 1);
}
int main() {
    int n;
    ll num;
    fac[0] = fac[1] = 1;
    for (int i = 2; i < 20; ++i) fac[i] = fac[i - 1] * i;
    scanf("%d", &n);
    FOR(i, n) {
        scanf("%I64d", &num);
        if (num <= 2 || ok(num, 19)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
