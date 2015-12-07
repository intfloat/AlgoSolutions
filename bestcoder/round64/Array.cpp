#include <stdio.h>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll> len(59), sm(59);
void preprocess() {
    len[0] = sm[0] = 0;
    for (int i = 1; i < 59; ++i) {
        len[i] = 2ll * len[i - 1] + 1;
        sm[i] = 2ll * sm[i - 1] + len[i - 1] + 1;
    }
}
ll solve(ll num) {
    if (num == 0) return 0ll;
    int pos = upper_bound(len.begin(), len.end(), num) - len.begin() - 1;
    ll res = sm[pos];
    if (len[pos] == num) {
        return res;
    }
    else {
        return res + (num - len[pos]) + solve(num - len[pos] - 1);
    }
}
int main() {
    preprocess();
    int T;
    scanf("%d", &T);
    ll M;
    for (int i = 0; i < T; ++i) {
        scanf("%lld", &M);
        printf("%lld\n", solve(M));
    }
    return 0;
}
