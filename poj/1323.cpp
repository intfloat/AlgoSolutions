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

int main() {
    int n, m, card[55], cnt = 1;
    bool check[1005];
    while (cin >> m >> n) {
        if (n == 0 && m == 0) break;
        memset(check, false, sizeof(check));
        FOR(i, n) { cin >> card[i]; check[card[i]] = true; }
        sort(card, card + n, greater<int>());

        vector<int> oppo;
        for (int i = n * m; i >= 1; --i) {
            if (oppo.size() >= n) break;
            if (!check[i]) oppo.push_back(i);
        }
        assert(oppo.size() == n);

        int res = 0;
        FOR(i, n) {
            if (card[i] > oppo[0]) { ++res; oppo.erase(oppo.end() - 1); }
            else oppo.erase(oppo.begin());
        }
        cout << "Case " << cnt++ << ": " << res << endl;
    }
    return 0;
}
