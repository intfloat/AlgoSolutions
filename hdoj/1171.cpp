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

const int MAX_N = 50 * 50 * 100 + 5;
int main() {
    int N, V, M;
    bool prev[MAX_N], cur[MAX_N];
    while (cin >> N && N >= 0) {
        vector<int> value, quant;
        int up = 0;
        FOR(i, N) {
            cin >> V >> M;
            up += V * M;
            value.push_back(V);
            quant.push_back(M);
        }
        memset(prev, false, sizeof(prev));
        memset(cur, false, sizeof(cur));
        FOR(i, quant[0] + 1) prev[value[0] * i] = cur[value[0] * i] = true;
        for (int i = 1; i < value.size(); ++i) {
            for (int j = 0; j <= up; ++j) {
                if (!prev[j]) continue;
                for (int k = 0; k <= quant[i]; ++k) {
                    cur[j + k * value[i]] = true;
                }
            }
            FOR(j, up + 1) prev[j] = cur[j];
        }
        for (int i = (up + 1) / 2; i <= up; ++i) {
            if (cur[i]) { cout << i << " " << up - i << endl; break; }
        }
    }
    return 0;
}
