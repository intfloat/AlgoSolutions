#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
const bool LEFT = 0;
const bool RIGHT = 1;

int main() {
    ll h, n, res;
    scanf("%I64d %I64d", &h, &n);
    // [0, 2^h), a perfect Huffman Tree
    --n;
    res = h;
    bool status = LEFT;
    int level = 0;
    for (level = 0; level < h; ++level) {
        ll bit = (1ll << (h - level - 1)) & n;
        bit = (bit > 0);
        if (bit == status)
            status = !status;
        else {
            res += (1ll << (h - level)) - 1;
            status = !bit;
        }
    }
    printf("%I64d\n", res);
    return 0;
}
