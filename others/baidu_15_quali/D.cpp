#include <stdio.h>
#include <iostream>
#include <cmath>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const double PI = acos(-1);
void solve() {
    int n;
    double a, r;
    scanf("%d %lf %lf", &n, &a, &r);    
    double dis = a / (2.0 * tan(PI / n));    
    if (dis >= r) {
        printf("Give me a kiss!\n");
    }
    else {
        printf("I want to kiss you!\n");
    }
    return;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(tt, T) {
        printf("Case #%d:\n", tt + 1);
        solve();
    }
    return 0;
}
