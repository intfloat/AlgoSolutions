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
typedef long long ll;
int MOD, ff;
vector<int> cc;
inline int pw(int number, int p) {
    ll ret = 1;
    for (int i = 1; i <= p; ++i) {
        ret = (ret * ret) % MOD;
        ret = (ret * number) % MOD;
    }
    return ret;
}
class Powerit {
public:
    int calc(int, int, int);
};

int Powerit::calc(int n, int k, int m) {
    vector<vector<int> > factors(n + 1, vector<int>());
    vector<bool> prime(n + 1, true);
    cc.resize(n + 1);
    MOD = m;
    for (int i = 2; i <= n; ++i) {
        if (!prime[i]) continue;
        cc[i] = pw(i, k);
        factors[i].push_back(i);
        for (int j = 2 * i; j <= n; j += i) {
            prime[j] = false;
            factors[j].push_back(i);
        }
    }
    ll res = 1, cur;
    for (int i = 2; i <= n; ++i) {
        int val = i;
        cur = 1;
        for (int j = 0; j < factors[i].size(); ++j) {
            ff = factors[i][j];
            while (val % ff == 0) {
                cur = (cur * cc[ff]) % MOD;
                val /= ff;
            }
        }
        res = (res + cur) % MOD;
    }
    return res;
}

// <%:testing-code%>
//Powered by [KawigiEdit] 2.0!
