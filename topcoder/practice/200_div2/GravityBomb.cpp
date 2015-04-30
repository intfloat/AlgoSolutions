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
#include <string.h>
#include <limits.h>

using namespace std;

class GravityBomb {
public:
    vector <string> aftermath(vector <string>);
};

vector <string> GravityBomb::aftermath(vector <string> board) {
    int cnt[55];
    memset(cnt, 0, sizeof(cnt));
    int row = board.size();
    int col = board[0].size();
    int mn = INT_MAX;
    for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j) {
        cnt[j] += (board[i][j] == 'X');
    }
    for (int i = 0; i < col; ++i) mn = min(mn, cnt[i]);
    vector<string> res;
    string s = "";
    for (int i = 0; i < col; ++i) s += '.';
    for (int i = 0; i < row; ++i) res.push_back(s);
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < cnt[i]-mn; ++j) res[row - 1 - j][i] = 'X';
    }
    return res;
}


//Powered by [KawigiEdit] 2.0!