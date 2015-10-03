#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

int main() {
    // freopen("cow.in", "r", stdin);
    // freopen("cow.out", "w", stdout);    
    int N;
    scanf("%d", &N);
    char *s = new char[N + 1];
    scanf("%s", s);
    vector<int> cs(N), os(N), ws(N);
    cs[0] = os[0] = ws[0] = 0;
    FOR(i, N) {
        if (i > 0) {
            cs[i] = cs[i - 1];
            os[i] = os[i - 1];
            ws[i] = ws[i - 1];
        }
        if (s[i] == 'C') ++cs[i];
        else if (s[i] == 'O') ++os[i];
        else if (s[i] == 'W') ++ws[i];
    }
    long long res = 0;
    FOR(i, N) {
        if (s[i] == 'O') {
            res = res + (long long)cs[i] * (ws[N - 1] - ws[i]);
        }
    }
    printf("%lld\n", res);
    return 0;
}
