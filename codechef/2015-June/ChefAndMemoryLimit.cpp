#include <stdio.h>
using namespace std;
int main() {
    int T, N, cur, val;
    long long res;
    scanf("%d", &T);
    for (int tt = 0; tt < T; ++tt) {
        scanf("%d", &N);
        res = cur = 0;
        for (int i = 0; i < N; ++i) {
            scanf("%d", &val);
            if (val > cur) res += (val - cur);
            cur = val;
        }
        printf("%lld\n", res);
    }
    return 0;
}
