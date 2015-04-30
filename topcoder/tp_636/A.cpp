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

class ChocolateDividingEasy {
public:
    int findBest(vector <string>);
    int arr[55][55];
    int get(int r1, int c1, int r2, int c2) {
        int res = arr[r2][c2];
        if (c1 > 0) res -= arr[r2][c1 - 1];
        if (r1 > 0) res -= arr[r1 - 1][c2];
        if (r1 > 0 && c1 > 0) res += arr[r1 - 1][c1 - 1];           
        return res;
    }
};

int ChocolateDividingEasy::findBest(vector <string> chocolate) {
    memset(arr, 0, sizeof(arr));
    int row = chocolate.size();
    int col = chocolate[0].size();
    arr[0][0] = chocolate[0][0] - '0';
    for (int i = 1; i < col; ++i) arr[0][i] = chocolate[0][i] - '0' + arr[0][i - 1];
    for (int i = 1; i < row; ++i) arr[i][0] = chocolate[i][0] - '0' + arr[i - 1][0];
    for (int i = 1; i < row; ++i)
    for (int j = 1; j < col; ++j)
        arr[i][j] = arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1] + chocolate[i][j] - '0';
    int res = -1;
    for (int c1 = 0; c1 < col; ++c1)
    for (int c2 = c1 + 1; c2 < col - 1; ++c2)
    for (int r1 = 0; r1 < row; ++r1)
    for (int r2 = r1 + 1; r2 < row - 1; ++r2) {
        vector<int> v;
        v.push_back(get(0, 0, r1, c1));
        v.push_back(get(0, c1 + 1, r1, c2));
        v.push_back(get(0, c2 + 1, r1, col - 1));

        v.push_back(get(r1 + 1, 0, r2, c1));
        v.push_back(get(r1 + 1, c1 + 1, r2, c2));
        v.push_back(get(r1 + 1, c2 + 1, r2, col - 1));

        v.push_back(get(r2 + 1, 0, row - 1, c1));
        v.push_back(get(r2 + 1, c1 + 1, row - 1, c2));
        v.push_back(get(r2 + 1, c2 + 1, row - 1, col - 1));

        int mn = *min_element(v.begin(), v.end());
        res = max(res, mn);
    }
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!