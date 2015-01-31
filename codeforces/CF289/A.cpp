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
    long long arr[15][15];
    int n;
    cin >> n;
    FOR(i, n) arr[0][i] = arr[i][0] = 1;
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < n; ++j)
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
    cout << arr[n - 1][n - 1] << endl;
    return 0;
}
