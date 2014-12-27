// this problem actually has a much simpler
// solution in constant time, but I just want to
// practice generating function
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

const int MAX_N = 9005;
int main() {
    int n[3], val[3];
    val[1] = 2; val[2] = 5;
    bool prev[MAX_N], cur[MAX_N];
    while (cin >> n[0] >> n[1] >> n[2]) {
        if (n[0] == 0 && n[1] == 0 && n[2] == 0) break;
        memset(prev, false, sizeof(prev));
        memset(cur, false, sizeof(cur));
        int up = n[0] + 2 * n[1] + 5 * n[2];
        FOR(i, n[0] + 1) prev[i] = cur[i] = true;
        for (int i = 1; i < 3; ++i) {
            for (int j = 0; j <= up; ++j) {
                if (!prev[j]) continue;
                for (int k = 0; k <= n[i]; ++k) {
                    cur[j + k * val[i]] = true;
                }
            }
            FOR(j, MAX_N) prev[j] = cur[j];
        }
        FOR(i, MAX_N) {
            if (!cur[i]) { cout << i << endl; break; }
        }
    }
    return 0;
}
