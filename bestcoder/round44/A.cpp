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
const int score[] = {4, 6, 8, 10};
void solve() {
    int res = 0;
    FOR(i, 4) {
        int a, b;
        scanf("%d %d", &a, &b);
        int cur = (250 - a) * score[i] - 50 * b;
        cur = max(cur, score[i] * 100);
        res += cur;
    }
    cout << res << endl;
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
