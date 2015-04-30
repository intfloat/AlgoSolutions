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
using namespace std;

int n;
vector<int> primes;
int main() {    
    cin >> n;   
    for (int i = 2; i <= n; ++i) {
        bool ok = true;
        for (int j = 2; j * j <= i; ++j) {
            ok = ok && (i % j);
        }
        if (ok) primes.push_back(i);
    }   
    long long res[170][1005];
    memset(res, 0, sizeof(res));
    res[0][0] = 1;
    for (int i = 1; i <= primes.size(); ++i) {      
        for (int j = 0; j <= n; ++j) {
            res[i][j] = res[i - 1][j];
            int cur = primes[i - 1];
            while (j - cur >= 0) {
                res[i][j] += res[i - 1][j - cur];
                cur *= primes[i - 1];
            }
        }
    }
    cout << accumulate(res[primes.size()], res[primes.size()] + n + 1, 0ll) << endl;
    return 0;
}
