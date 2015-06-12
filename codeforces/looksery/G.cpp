#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    int N;
    scanf("%d", &N);
    vector<int> arr(N);
    FOR(i, N) {
        scanf("%d", &arr[i]);
        arr[i] += i;
    }
    sort(arr.begin(), arr.end());
    for (int i = 1; i < N; ++i) {
        if (arr[i] == arr[i - 1]) {
            printf(":(\n");
            return 0;
        }
    }
    FOR(i, N) printf("%d ", arr[i] - i);
    printf("\n");
    return 0;
}
