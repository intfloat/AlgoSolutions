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
using namespace std;

double area;

double solve(double x, double y, int number) {
    assert(number >= 1);
    if (number == 1) return max(x, y) / min(x, y);
    double res = 1e9;
    for (int i = 1; i*2 <= number; ++i) {
        double h = i * area / y;
        res = min(res, max(solve(h, y, i), solve(x - h, y, number - i)));       
        double w = i * area / x;
        res = min(res, max(solve(x, w, i), solve(x, y - w, number - i)));       
    }
    return res;
}

int main() {
    double x, y;
    int n;
    cin >> x >> y >> n;
    area = (x * y) / n;
    double res = solve(x, y, n);    
    cout << fixed << setprecision(6) << res << endl;
    return 0;
}
