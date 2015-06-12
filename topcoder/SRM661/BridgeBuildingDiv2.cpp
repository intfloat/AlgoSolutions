#include <vector>
#include <list>
#include <map>
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

using namespace std;

const int INF = INT_MAX / 4;
class BridgeBuildingDiv2 {
public:
    int minDiameter(vector <int>, vector <int>, int);
};

int BridgeBuildingDiv2::minDiameter(vector <int> a, vector <int> b, int K) {
    int N = 2 * (a.size() + 1);
    int col = a.size() + 1;
    vector<vector<int> > g(N, vector<int>(N, INF)), tmp;
    for (int i = 0; i < a.size(); ++i) {
        g[i][i + 1] = g[i + 1][i] = a[i];
        g[i + col][i + 1 + col] = g[i + 1 + col][i + col] = b[i];
    }
    int res = INF, cur;
    for (int i = 0; i < N; ++i) g[i][i] = 0;
    for (int i = 1; i < (1 << col); ++i) {
        if (__builtin_popcount(i) != K) continue;
        for (int j = 0; j < col; ++j) {
            if (i & (1 << j)) {
                g[j][j + col] = g[j + col][j] = 0;
            }
        }
        tmp = g;
        for (int k = 0; k < N; ++k) {
            for (int x = 0; x < N; ++x) {
                for (int y = 0; y < N; ++y) {
                    tmp[x][y] = min(tmp[x][y], tmp[x][k] + tmp[k][y]);
                }
            }
        }
        cur = 0;
        for (int x = 0; x < N; ++x) {
            cur = max(cur, *max_element(tmp[x].begin(), tmp[x].end()));
        }
        res = min(res, cur);
        for (int j = 0; j < col; ++j) {
            if (i & (1 << j)) {
                g[j][j + col] = g[j + col][j] = INF;
            }
        }
    }
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
