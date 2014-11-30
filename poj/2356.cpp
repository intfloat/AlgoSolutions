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

const int MAX_N = 10005;
int main() {
    int N, arr[MAX_N], sm[MAX_N];
    map<int, int> m;
    cin >> N;
    memset(sm, 0, sizeof(sm));
    FOR(i, N) cin >> arr[i];
    sm[0] = arr[0];
    for (int i = 1; i < N; ++i) sm[i] = sm[i - 1] + arr[i];
    FOR(i, N) {
        if (sm[i] % N == 0) {
            cout << i + 1 << endl;
            FOR(j, i + 1) cout << arr[j] << endl;
            return 0;
        }
        else {
            int rm = sm[i] % N;
            if (m.find(rm) != m.end()) {
                cout << i - m[rm] << endl;
                for (int j = m[rm] + 1; j <= i; ++j) cout << arr[j] << endl;
                return 0;
            }
            else m[rm] = i;
        }
    }
    return 0;
}
