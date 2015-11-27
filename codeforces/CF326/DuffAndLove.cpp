#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin >> n;
    ll res = 1;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            res *= i;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) res *= n;
    cout << res << endl;
    return 0;
}
