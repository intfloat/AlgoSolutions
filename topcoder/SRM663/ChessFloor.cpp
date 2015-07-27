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

using namespace std;

class ChessFloor {
public:
    int minimumChanges(vector <string>);
};

int ChessFloor::minimumChanges(vector <string> floor) {
    int N = floor.size();
    int cnt1[26], cnt2[26];
    memset(cnt1, 0, sizeof cnt1);
    memset(cnt2, 0, sizeof cnt2);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if ((i + j) % 2 == 0) {
                ++cnt1[floor[i][j] - 'a'];
            }
            else {
                ++cnt2[floor[i][j] - 'a'];
            }
        }
    }
    int mx = 0;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (i == j) {
                continue;
            }
            mx = max(cnt1[i] + cnt2[j], mx);
        }
    }
    return N * N - mx;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
