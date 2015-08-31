#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
inline bool check(int x) {
    while (x % 2 == 0) x /= 2;
    while (x % 3 == 0) x /= 3;
    return (x == 1);
}
int main() {
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    FOR(i, n) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i < n; ++i) {
        int g = __gcd(arr[i - 1], arr[i]);
        int x = arr[i - 1] / g;
        int y = arr[i] / g;
        if (!check(x) || !check(y)) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}
