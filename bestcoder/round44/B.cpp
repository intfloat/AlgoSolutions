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
const ll MOD = 998244353ll;
vector<int> arr;
ll res;
void merge_sort(int left, int right, int pos) {
    if (left >= right || pos > 30) return;
    vector<int> odd, even;
    int mask = (1 << pos);
    for (int i = left; i <= right; ++i) {
        if (arr[i] & mask) odd.push_back(arr[i]);
        else even.push_back(arr[i]);
    }
    res = (res + ((ll)odd.size() * (ll)even.size() * (ll)mask) % MOD) % MOD;
    if (odd.empty() || even.empty()) {
        merge_sort(left, right, pos + 1);
        return;
    }
    int mid = left + odd.size() - 1;
    for (int i = left; i <= mid; ++i) arr[i] = odd[i - left];
    for (int i = mid + 1; i <= right; ++i) arr[i] = even[i - mid - 1];
    merge_sort(left, mid, pos + 1);
    merge_sort(mid + 1, right, pos + 1);
    return;
}
void solve() {
    int n;
    scanf("%d", &n);
    arr.resize(n);
    FOR(i, n) scanf("%d", &arr[i]);
    res = 0;
    merge_sort(0, n - 1, 0);
    cout << (res * 2ll) % MOD << endl;
    return;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(tt, T) {
        cout << "Case #" << tt + 1 << ": ";
        solve();
    }
    return 0;
}
