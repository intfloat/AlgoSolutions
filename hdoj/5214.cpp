#include <stdio.h>
#include <algorithm>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

void solve() {
    unsigned int N, left, right, a, b, c, d;
    scanf("%u %u %u %u %u %u %u", &N, &left, &right, &a, &b, &c, &d);    
    unsigned int mn = max(left, right), mx = min(left, right);
    unsigned int cl = left, cr = right;
    FOR(i, N - 1) {
        cl = cl * a + b;
        cr = cr * c + d;        
        mn = min(mn, max(cl, cr));
        mx = max(mx, min(cl, cr));
    }
    if (mn >= mx) {
        printf("NO\n");
        return;
    }
    cl = left; cr = right;
    FOR(i, N) {
        if (min(cl, cr) > mn && max(cl, cr) < mx) {
            printf("YES\n");
            return;
        }
        cl = cl * a + b;
        cr = cr * c + d;        
    }
    printf("NO\n");
    return;
}

int main() {
    int T;
    scanf("%d", &T);
    FOR(tt, T) solve();
    return 0;
}
