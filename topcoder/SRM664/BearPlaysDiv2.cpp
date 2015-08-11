#include <vector>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <deque>
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

using namespace std;
typedef pair<int, int> point;
class BearPlaysDiv2 {
public:
    string equalPiles(int, int, int);
    point get(int x, int y) {
        if (x > y) swap(x, y);
        y -= x;
        x += x;
        if (x > y) swap(x, y);
        return make_pair(x, y);
    }
};

string BearPlaysDiv2::equalPiles(int A, int B, int C) {
    if ((A + B + C) % 3) {
        return "impossible";
    }
    int avg = (A + B + C) / 3;
    bool dp[1505][1505];
    memset(dp, false, sizeof dp);
    queue<point> q;
    q.push(make_pair(min(A, B), max(A, B)));
    dp[min(A, B)][max(A, B)] = true;
    while (!q.empty()) {
        point tp = q.front();
        q.pop();
        point cur = get(tp.first, tp.second);
        if (!dp[cur.first][cur.second]) {
            dp[cur.first][cur.second] = true;
            q.push(cur);
        }
        cur = get(tp.first, A + B + C - tp.first - tp.second);
        if (!dp[cur.first][cur.second]) {
            dp[cur.first][cur.second] = true;
            q.push(cur);
        }
        cur = get(tp.second, A + B + C - tp.first - tp.second);
        if (!dp[cur.first][cur.second]) {
            dp[cur.first][cur.second] = true;
            q.push(cur);
        }
    }
    if (dp[avg][avg]) {
        return "possible";
    }
    else return "impossible";
}

// <%:testing-code%>
//Powered by [KawigiEdit] 2.0!
