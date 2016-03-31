#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, d, h;
    cin >> n >> d >> h;
    if (d == 1 && h == 1) {
        if (n != 2) printf("-1\n");
        else printf("1 2\n");
    }
    else if (h + h < d) {
        printf("-1\n");
    }
    else {
        int prev = 1;
        for (int i = 2; i < h + 2; ++i) {
            printf("%d %d\n", prev, i);
            prev = i;
        }
        prev = 1;
        for (int i = h + 2; i < h + 2 + (d - h); ++i) {
            printf("%d %d\n", prev, i);
            prev = i;
        }
        for (int i = d + 2; i <= n; ++i) {
            if (d > h) printf("1 %d\n", i);
            else printf("2 %d\n", i);
        }
    }
    return 0;
}
