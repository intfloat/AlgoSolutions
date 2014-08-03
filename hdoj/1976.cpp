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

using namespace std;

int main() {
    long long n, m;
    long long arr[15];
    while (cin>>n>>m) {
        int res = 0;
        for (int i=0; i<m; ++i){
            cin>>arr[i];
            if (arr[i] == 0) {--i; --m; }
        }
        for (int i=1; i<(1<<m); ++i) {
            int bits = __builtin_popcount(i);
            long long lcm = 1;
            for (int j=0; j<m; j++) {
                if ((1<<j)&i) {
                    lcm = (lcm * arr[j]) / __gcd(lcm, arr[j]);
                }
            }
            if (bits&1) res += (n-1)/lcm;
            else res -= (n-1)/lcm;
        }
        cout<<res<<endl;
    }
    return 0;
}
