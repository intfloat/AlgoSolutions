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
typedef pair<int, int> point;
vector<int> arr, cur;
int N;
bool check(int mid) {
    cur = arr;
    cur[0] -= mid;
    for (int i = 1; i < N; ++i) {
        if (cur[i - 1] + mid < cur[i]) {
            cur[i] = cur[i] - mid;
        }
        else if (cur[i - 1] < cur[i]) cur[i] = cur[i - 1] + 1;
        else if (cur[i - 1] >= cur[i] + mid) return false;
        else cur[i] = cur[i - 1] + 1;
    }
    return true;
}
inline void solve() {
    int left = 0, right = 1000005;
    scanf("%d", &N);
    arr.resize(N);
    FOR(i, N) scanf("%d", &arr[i]);
    while (left < right) {
        int mid = (left + right) / 2;
        if (check(mid)) right = mid;
        else left = mid + 1;
    }
    printf("%d\n", left);
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
