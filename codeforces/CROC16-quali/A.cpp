#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    if (n > a * b) {
        printf("-1\n");
        return 0;
    }
    int odd = 1, even = 2;
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            if ((i + j) % 2 == 0) {
                if (odd <= n) {
                    printf("%d ", odd);
                    odd += 2;
                }
                else printf("0 ");
            }
            else {
                if (even <= n) {
                    printf("%d ", even);
                    even += 2;
                }
                else printf("0 ");
            }
        }
        printf("\n");
    }
    return 0;
}
