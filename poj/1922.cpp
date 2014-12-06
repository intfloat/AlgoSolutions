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

const double DIS = 4.5 * 3600;
int main() {
    int N;
    while (cin >> N && N) {
        double res = 1e9;
        int v, t;
        FOR(i, N) {
            cin >> v >> t;
            if (t < 0) continue;
            res = min(res, t + DIS / v);
        }
        cout << ceil(res) << endl;
    }
    return 0;
}
