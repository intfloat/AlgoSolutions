#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    FOR(i, n) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 1000; ++i) {
        int val = arr[0] + i;
        int d = i;
        for (int j = 1; j < n; ++j) {
            if (arr[j] >= val) {
                d -= (arr[j] - val + 1);
            }
        }
        if (d >= 0) {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}
