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

const int MAX_N = 100005;
int main() {
    int c, n, arr[MAX_N];
    long long sm[MAX_N];
    while (scanf("%d%d", &c, &n)) {
        if (c == 0 && n == 0) break;
        FOR(i, n) scanf("%d", arr + i);
        sm[0] = arr[0];
        if (arr[0] % c == 0) { cout << 1 << endl; continue; }
        bool ok = false;
        for (int i = 1; i < n; ++i) {
            if (arr[i] % c == 0) { cout << i + 1 << endl; ok = true; break; }
            sm[i] = sm[i - 1] + arr[i];
            int rm = sm[i] % c;
            if (rm == 0) {
                printf("1");
                for (int j = 1; j <= i; ++j) printf(" %d", j + 1);
                ok = true;
                break;
            }
        }
        if (ok) continue;
        map<int, int> m;
        FOR(i, n) {
            int rm = sm[i] % c;
            if (m.find(rm) != m.end()) {
                for (int j = m[rm] + 1; j < i; ++j) printf("%d ", j + 1);
                printf("%d\n", i + 1);
                break;
            }
            else m[rm] = i;

        }
    }
    return 0;
}
