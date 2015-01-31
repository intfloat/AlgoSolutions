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

vector<double> arr1, arr2;
const double ONE = 1.0;

void precompute(int N) {
    arr1.resize(N + 1); arr2.resize(N + 1);
    arr1[0] = arr2[0] = 0;
    for (int i = 1; i <= N; ++i) {
        arr1[i] = arr1[i - 1] + ONE / i;
        arr2[i] = arr2[i - 1] + i * ONE / (N - i + 1);
    }
    return;
}

int main() {
    string s;
    cin >> s;
    precompute(s.size());
    double res = 0;
    int N = s.size();
    FOR(i, s.size()) {
        if (s[i] == 'I' || s[i] == 'E' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y' || s[i] == 'A') {
            int mx = max(i + 1, N - i);
            int mn = min(i + 1, N - i);
            res += mn + mn * (arr1[mx] - arr1[mn]) + arr2[mn - 1];
        }
    }
    cout << fixed << setprecision(8) << res << endl;
    return 0;
}
