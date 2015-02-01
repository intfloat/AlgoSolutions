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
int main() {
    int row, col;
    cin >> row >> col;
    vector<vector<ll> > arr(row, vector<ll>(col, 0));
    ll mn = INT_MAX;
    ll mx = INT_MIN;
    pair<int, int> pos;
    FOR(i, row) FOR(j, col) {
        cin >> arr[i][j];
        if (arr[i][j] < mn) {
            mn = arr[i][j];
            pos = make_pair(i, j);
        }
        mx = max(mx, arr[i][j]);
    }
    vector<ll> a(row, 0), b(col, 0);
    FOR(i, col) b[i] = arr[pos.first][i];
    FOR(i, row) a[i] = arr[i][pos.second] - b[pos.second];
    ll res = 0;
    FOR(i, row) FOR(j, col) {
        if (arr[i][j] > a[i] + b[j]) {
            cout << "NO" << endl;
            return 0;
        }
        ll t = a[i] + b[j] - arr[i][j];
        if (t == 0) continue;
        if (res == 0) res = t;
        else res = __gcd(res, t);
    }
    if (res == 0) res = mx + 1;
    else if (res <= mx) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cout << res << endl;
    FOR(i, row) cout << a[i] << " ";
    cout << endl;
    FOR(i, col) cout << b[i] << " ";
    cout << endl;
    return 0;
}
