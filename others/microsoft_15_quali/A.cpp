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

const string ms[] = {"January", "February", "March", "April", 
                    "May", "June", "July", "August", "September", 
                    "October", "November" , "December"};

int get_month(const string& s) {
    FOR(i, 12) {
        if (s == ms[i]) return i + 1;
    }
    assert(false);
    return -1;
}

int solve(int from, int to, int period) {
    if (from > to) return 0;
    return to / period - (from - 1) / period;
}

int main() {
    int T, day[2], year[2], month[2];
    string mstr;
    char ch;
    cin >> T;
    FOR(tt, T) {
        cin >> mstr >> day[0] >> ch >> year[0];
        month[0] = get_month(mstr);
        cin >> mstr >> day[1] >> ch >> year[1];
        month[1] = get_month(mstr);
        int from, to;
        if (month[0] <= 2) from = year[0];
        else from = year[0] + 1;
        if (month[1] > 2 || (month[1] == 2 && day[1] == 29)) to = year[1];
        else to = year[1] - 1;
        int res = solve(from, to, 4) - solve(from, to, 100) + solve(from, to, 400);
        cout << "Case #" << tt + 1 << ": " << res << endl;
    }
    return 0;
}
