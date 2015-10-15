#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll X, Y;
int main() {
    cin >> X >> Y;
    if (__gcd(X, Y) != 1) {
        printf("Impossible\n");
        return 0;
    }
    while (true) {
        if(X > Y) {
            ll n = X / Y;
            X %= Y;
            if (X == 0) {
                --n;
                X = Y;
            }
            printf("%I64dA", n);
        } else {
            ll n = Y / X;
            Y %= X;
            if (Y == 0) {
                --n;
                Y = X;
            }
            printf("%I64dB", n);
        }
        if (X == 1 && Y == 1) break;
    }
    printf("\n");
    return 0;
}
