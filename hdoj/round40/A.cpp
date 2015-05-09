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
typedef long long ll;

int main() {
    int T;
    cin >> T;
    FOR(tt, T) {
        ll area;
        cin >> area;
        ll bound = sqrt(area) + 1ll;
        ll res = (1ll + area) * 2ll;
        for (ll i = 2; i <= bound; ++i) {
            if (area % i == 0) {
                res = min(res, (i + area / i) * 2);
            }
        }
        cout << res << endl;
    }    
    return 0;
}
