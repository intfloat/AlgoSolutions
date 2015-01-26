#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

int main() {
    int r, x1, y1, x2, y2;
    scanf("%d %d %d %d %d", &r, &x1, &y1, &x2, &y2);
    long long sdis = (long long)(x1 - x2) * (x1 - x2) + (long long)(y1 - y2) * (y1 - y2);
    long long d = static_cast<long long>(sqrt(sdis));
    long long res;
    if (sdis == 0) res = 0;
    else if (d * d == sdis) res = (d - 1) / (2 * r) + 1;
    else res = d / (2 * r) + 1;
    printf("%I64d", res);
    return 0;
}
