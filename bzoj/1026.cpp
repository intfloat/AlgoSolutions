/**************************************************************
    Problem: 1026
    User: BananaTree
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1316 kb
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
#include <sstream>

using namespace std;
stringstream ss;
long long dp[35][15][2][2];
string cur;
int len;

int solve(int num, int pos, bool z, bool margin) {
    if (pos >= len) return 0;
    if (dp[pos][num][z][margin] > 0) return dp[pos][num][z][margin];
    if (pos == len - 1) {
        if (z && 0 == num) return 0;
        else {
            dp[pos][num][z][margin] = 1;
            return dp[pos][num][z][margin];
        }
    }
    int cnt = 0;
    for (int i = 0; i <= 9; ++i) {
        if (z && i == 0) cnt += solve(i, pos+1, z, false);
        else if (z && i != 0) cnt += solve(i, pos+1, false, false);
        else if (abs(i - num) < 2) continue;
        else if (!margin) cnt += solve(i, pos+1, false, false);     
        else if (margin && i + '0' == cur[pos+1]) cnt += solve(i, pos+1, false, true);
        else if (margin && i + '0' > cur[pos+1]) continue;
        else if (margin && i + '0' < cur[pos+1]) cnt += solve(i, pos+1, false, false);
    }
    dp[pos][num][z][margin] = cnt;
    return cnt;
}

int get(long long num) {    
    ss.clear();
    ss << num;
    ss >> cur;
    int msb = cur[0] - '0';
    int res = 0;
    len = cur.size();
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= msb; ++i) {
        if (i == 0) res += solve(0, 0, true, false);        
        else if (i == msb) res += solve(i, 0, false, true);
        else res += solve(i, 0, false, false);
    }
    return res;
}

int main() {
    long long a, b;
    cin >> a >> b;
    int res = get(b) - get(a - 1);
    cout << res << endl;
    return 0;
}
