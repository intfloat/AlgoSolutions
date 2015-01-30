#include <algorithm>
#include <stdio.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

int main() {
    int N, number[1005];
    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; ++i) scanf("%d", number + i);
        int res = 0;
        for (int i = 0; i < N; ++i) res ^= number[i];
        res = res & (-res);
        int r1 = 0, r2 = 0;
        for (int i = 0; i < N; ++i) {
            if ((res & number[i]) > 0) r1 ^= number[i];
            else r2 ^= number[i];
        }
        if (r1 > r2) swap(r1, r2);
        printf("%d %d\n", r1, r2);
    }
    return 0;
}


