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
    int n, k;
    vector<ll> A, B;
    vector<double> C;
    while (scanf("%d %d", &n, &k) != EOF) {
        if (n == 0 && k == 0) break;
        A.resize(n); B.resize(n); C.resize(n);
        FOR(i, n) scanf("%lld", &A[i]);
        FOR(i, n) scanf("%lld", &B[i]);
        double left = 0, right = 1.0;
        while (right - left > 1e-8) {
            // cout << left << " " << right << endl;
            double mid = (right + left) / 2;
            FOR(i, n) C[i] = (double)A[i] - mid * B[i];
            sort(C.begin(), C.end(), greater<double>());
            double val = accumulate(C.begin(), C.begin() + n - k, 0.0);
            if (val < 0) right = mid;
            else left = mid;
        }
        int res = round(left * 100);
        printf("%d\n", res);
    }
    return 0;
}
