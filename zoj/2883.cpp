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
    int T, p, n;
    cin >> T;
    while (T--) {
        vector<int> arr;
        cin >> n;
        FOR(i, n) { cin >> p; arr.push_back(p); }
        sort(arr.begin(), arr.end(), greater<int>());
        int res = 0;
        for (int i = 2; i < arr.size(); i += 3) res += arr[i];
        cout << res << endl;
    }
    return 0;
}
