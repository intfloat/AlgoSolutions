#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    ll res = 0;
    int odd = 1001;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 && arr[i] < odd) odd = arr[i];
        res += arr[i];
    }
    if (n == 1 && arr[0] % 2) {
        printf("NIESTETY\n");
    }
    else {
        if (res % 2) res -= odd;
        printf("%lld\n", res);
    }
    return 0;
}
