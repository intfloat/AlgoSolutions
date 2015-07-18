#include <stdio.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
int N, res, t;
int main() {
    while (scanf("%d", &N) != EOF) {
        res = 2 * N;
        FOR(i, N) FOR(j, N) {
            scanf("%d", &t);
            res += t;
        }
        printf("%d\n", res);
    }
    return 0;
}
