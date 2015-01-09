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

int main() {
    int T;
    cin >> T;
    FOR(tt, T) {
        cout << "Case #" << tt + 1 << ": ";
        string number;
        cin >> number;
        vector<string> res;
        res.emplace_back(number);
        for (int i = 0; i < number.size(); ++i)
            for (int j = i + 1; j < number.size(); ++j) {
                if (i == 0 && number[j] == '0') continue;
                string tmp = number;
                swap(tmp[i], tmp[j]);
                res.emplace_back(tmp);
            }
        sort(res.begin(), res.end());
        cout << res[0] << " " << res[res.size() - 1] << endl;
    }
    return 0;
}
