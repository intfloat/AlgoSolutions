/**************************************************************
    Problem: 1041
    User: BananaTree
    Language: C++
    Result: Accepted
    Time:92 ms
    Memory:1284 kb
****************************************************************/
 
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
 
int main() {
    long long r;
    cin >> r;
    long long d, a, b;
    long long ans = 0;
    for (d = 1; d * d <= 2*r; ++d) {
        if ((2 * r) % d) continue;
        long long t = (2 * r) / d;
        for (a = 1; a * a <= t; ++a) {
            b = sqrt(t - a * a);
            if (b * b != t - a * a) continue;
            if (a >= b) continue;
            if (__gcd(a, b) > 1) continue;
            // cout << d << " " << a << " " << b << endl;
            // cout << "X: " << - a * a * d + r << endl;
            ++ans;
        }
        if (d * d == 2 * r) continue;
        t = d;      
        for (a = 1; a * a <= t; ++a) {
            b = sqrt(t - a * a);
            if (b * b != t - a * a) continue;
            if (a >= b) continue;
            if (__gcd(a, b) > 1) continue;
            // cout << t << " " << a << " " << b << endl;
            // cout << "X: " << - a * a * (2*r/d) + r << endl;
            ++ans;
        }
    }
    ans = (ans + 1) * 4;
    cout << ans << endl;
    return 0;
}
