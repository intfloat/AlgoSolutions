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
#include <cassert>

using namespace std;

class MissingLCM {
public:
    int getMin(int);
};

int MissingLCM::getMin(int N) {
    if (N == 1) return 2;
    vector<int> primes;
    vector<int> ok(N + 1, true);
    map<int, int> cnt;
    int t;
    for (int i = 2; i <= N; ++i) {
        if (!ok[i]) continue;
        primes.push_back(i);
        cnt[i] = 1;
        for (int j = 2 * i; j <= N; j += i) {
            t = j;
            ok[j] = false;
            int acc = 0;
            while (t % i == 0) {
                ++acc; t /= i;
            }
            if (acc > cnt[i]) cnt[i] = acc;
        }
    }
    int val, cur, res = N, tp;
    for (int i = 0; i < primes.size(); ++i) {
        val = cnt[primes[i]];
        cur = (N + 1 + primes[i]) - (N + 1) % primes[i];
        while ((cur - primes[i]) > N) cur -= primes[i];
        while (true) {
            tp = cur;
            int acc = 0;
            while (tp % primes[i] == 0) {
                ++acc; tp /= primes[i];
            }
            if (acc >= val) {
                res = max(res, cur);
                break;
            }
            cur += primes[i];
        }
    }
    return res;
}

// <%:testing-code%>
//Powered by [KawigiEdit] 2.0!
