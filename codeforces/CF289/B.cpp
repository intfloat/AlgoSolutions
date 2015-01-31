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
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    arr.resize(n);
    FOR(i, n) cin >> arr[i];
    int mx = *max_element(arr.begin(), arr.end());
    int mn = *min_element(arr.begin(), arr.end());
    if (mx - mn > k) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    FOR(i, n) {
        int rem = arr[i] % k;
        int num = arr[i] / k;
        FOR(j, rem) FOR(p, num + 1) cout << j + 1 << " ";
        for (int j = rem; j < k; ++j) FOR(p, num) cout << j + 1 << " ";
        cout << endl;
    }
    return 0;
}
