#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef tuple<int, int, int> piii;
int main() {
    int n, val;
    scanf("%d", &n);
    vector<piii> arr;
    for (int i = 2; i <= 2 * n; ++i) {
        for (int j = 1; j < i; ++j) {
            scanf("%d", &val);
            arr.push_back(make_tuple(val, i, j));
        }
    }
    sort(arr.begin(), arr.end(), greater<piii>());
    vector<int> res(2 * n + 1, -1);
    FOR(i, arr.size()) {
        int x = get<1>(arr[i]), y = get<2>(arr[i]);
        if (res[x] < 0 && res[y] < 0) {
            res[x] = y;
            res[y] = x;
        }
    }
    for (int i = 1; i <= 2 * n; ++i) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}
