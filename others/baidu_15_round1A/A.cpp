#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <cstdio>
#include <string>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const string WIN = "why am I so diao?";
const string LOSE = "madan!";
vector<ll> arr;
ll N, initial, K;
inline void solve() {
    scanf("%lld %lld %lld", &N, &initial, &K);
    arr.resize(N);
    FOR(i, N) scanf("%lld", &arr[i]);
    sort(arr.begin(), arr.end());
    int pos = upper_bound(arr.begin(), arr.end(), initial) - arr.begin();
    if (pos == N || arr.back() <= initial) { printf("%s\n", WIN.c_str()); return; }
    if (pos == 0) { printf("%s\n", LOSE.c_str()); return; }
    --pos;
    ll val = arr[pos];
    int ptr = pos;
    while (true) {
        while (ptr < N && arr[ptr] - val <= K) ++ptr;
        if (val >= arr.back()) { printf("%s\n", WIN.c_str()); return; }
        --K;
        if (val >= arr[ptr - 1]) { printf("%s\n", LOSE.c_str()); return; }
        val = arr[ptr - 1];
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
