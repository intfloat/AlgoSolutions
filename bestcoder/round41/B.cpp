#include <vector>
#include <list>
#include <limits.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
char cc[200005];
void solve() {
    int N;
    scanf("%d", &N);
    vector<string> arr(N);
    ll odd = 0, even = 0;
    FOR(i, N) {
        scanf(" %s", cc);
        arr[i] = cc;        
    }
    FOR(i, N) {
        if (arr[i].size() % 2) ++odd;
        else ++even;
    }
    sort(arr.begin(), arr.end());
    ll total = ((ll)N * (N - 1)) / 2;
    ll wins = (odd * (odd - 1)) / 2 + (even * (even - 1)) / 2;
    ll others = 0ll;
    for (int i = 0; i < N; ++i) {
        int ptr = i + 1;
        while (ptr < N && arr[ptr] == arr[i]) ++ptr;
        int cnt = ptr - i;
        others += (cnt * (cnt - 1)) / 2;
        i = ptr - 1;
    }
    wins -= others;
    wins = total - wins;
    ll g = __gcd(total, wins);
    total /= g; wins /= g;
    printf("%lld/%lld\n", wins, total);
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(tt, T) solve();
    return 0;
}
