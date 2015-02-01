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
const ll MOD = (ll)1e9 + 7;
int main() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    FOR(i, n) cin >> arr[i];
    vector<vector<ll> > res(n, vector<ll>(n, 0)), cont(n, vector<ll>(n, 0));
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i < n; ++i) {
            int j = i + len - 1;
            if (j >= n) continue;
            if (len == 1) { res[i][j] = cont[i][j] = 1; continue; }
            for (int pos = j; pos > i; --pos) {
                res[i][j] = (res[i][j] + cont[i][pos - 1] * res[pos][j]) % MOD;
                if (j + 1 < n && arr[pos] < arr[j + 1])
                    cont[i][j] = (cont[i][j] + cont[i][pos - 1] * res[pos][j]) % MOD;
            }
        }
    }
    cout << res[0][n - 1] % MOD << endl;
    return 0;
}
