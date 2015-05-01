#include <stdio.h>
#include <algorithm>
#include <string.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

const int MAX_N = 500005;
int N, bit[MAX_N], arr[MAX_N], order[MAX_N], t[MAX_N];
int get(int pos) {
    int res = 0;
    while (pos > 0) {
        res += bit[pos];
        pos -= pos & (-pos);
    }
    return res;
}

void add(int pos, int val) {
    while (pos < MAX_N) {
        bit[pos] += val;
        pos += pos & (-pos);
    }
}

int main() {
    while (scanf("%d", &N) != EOF && N) {
        FOR(i, N) scanf("%d", arr + i);
        FOR(i, N) t[i] = arr[i];
        sort(arr, arr + N);
        FOR(i, N) order[i] = lower_bound(arr, arr + N, t[i]) - arr + 1;
        long long res = 0;
        memset(bit, 0, (N + 1) * 4);
        FOR(i, N) {
            res += i - get(order[i]);
            add(order[i], 1);
        }
        printf("%lld\n", res);
    }
    return 0;
}
